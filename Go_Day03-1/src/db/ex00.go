package db

import (
	"bytes"
	"encoding/csv"
	"encoding/json"
	"log"
	"os"
	"strconv"
	"strings"
	"sync"

	"github.com/elastic/go-elasticsearch/v8"
)

type Place struct {
	ID       string    `json:"-"`
	Name     string    `json:"name"`
	Address  string    `json:"address"`
	Phone    string    `json:"phone"`
	Location GeoPoints `json:"location"`
}

func (p *Place) MarshalJSON() []byte {
	byteJSON, err := json.Marshal(p)
	if err != nil {
		log.Println(err)
	}
	return byteJSON
}

type GeoPoints struct {
	Latitude  float64 `json:"lat"`
	Longitude float64 `json:"lon"`
}

const numsOfBulks = 10
const bulkRequestSize = 1000
const mapping = `{
		"mappings": {
			"properties": {
				"name": {
					"type": "text"
				},
				"address": {
					"type": "text"
				},
				"phone": {
					"type": "text"
				},
				"location": {
					"type": "geo_point"
				}
			}
		}
	}`

func UpDataBase() {
	// Создание клиента
	es := createNewESClient()

	// Проверка есть ли индекс
	deleteIndexPlaces(es)

	// Создание нового идекса
	createNewPlacesIndex(es)

	// Добавление БД в Elastic
	addDBinES(es)
}

func createNewESClient() *elasticsearch.Client {
	log.Println("Creating new ES client ... ")
	client, err := elasticsearch.NewDefaultClient()
	if err != nil {
		log.Fatal(err)
	}
	return client
}

func deleteIndexPlaces(client *elasticsearch.Client) {
	log.Println("Checking existing index \"places\" ... ")
	exists, err := client.Indices.Exists([]string{"places"})
	if err != nil {
		log.Fatal(err)
	}
	defer exists.Body.Close()

	if exists.StatusCode == 200 {
		log.Println("Deleting index \"places\"")
		res, err := client.Indices.Delete([]string{"places"})
		if err != nil {
			log.Fatal(err)
		}
		defer res.Body.Close()

		if res.IsError() {
			log.Fatal(res.String())
		}
	}
}

func createNewPlacesIndex(client *elasticsearch.Client) {
	log.Println("Creating new index \"places\"")
	res, err := client.Indices.Create(
		"places",
		client.Indices.Create.WithBody(strings.NewReader(mapping)),
	)
	if err != nil {
		log.Fatal(err)
	}
	res.Body.Close()
}

func addDBinES(client *elasticsearch.Client) {
	log.Println("Adding DB in ES ... ")
	placeCh := make(chan Place, bulkRequestSize)
	var wg sync.WaitGroup
	go readDB(placeCh)

	for i := 0; i < numsOfBulks; i++ {
		wg.Add(1)
		go bulkRequest(client, placeCh, &wg)
	}

	wg.Wait()
}

func readDB(placeCh chan<- Place) {
	file, err := os.Open("../../materials/data.csv")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	reader := csv.NewReader(file)
	reader.Comma = '\t'
	reader.Read() // Пропуск первой строки

	for {
		str, err := reader.Read()
		if err != nil {
			break
		}

		lon, _ := strconv.ParseFloat(str[4], 64)
		lat, _ := strconv.ParseFloat(str[5], 64)
		p := Place{
			ID:      str[0],
			Name:    str[1],
			Address: str[2],
			Phone:   str[3],
			Location: GeoPoints{
				Latitude:  lat,
				Longitude: lon,
			},
		}

		placeCh <- p
	}
	close(placeCh)
}

func bulkRequest(client *elasticsearch.Client, placeCh <-chan Place, wg *sync.WaitGroup) {
	defer wg.Done()
	var bulkBody bytes.Buffer
	for i := 0; i < bulkRequestSize; i++ {
		place, ok := <-placeCh
		if !ok {
			break
		}

		// Создаем метаданные
		meta := map[string]interface{}{
			"index": map[string]interface{}{
				"_index": "places",
				"_id":    place.ID,
			},
		}
		metaJSON, err := json.Marshal(meta)
		if err != nil {
			log.Fatal(err)
		}

		bulkBody.Write(metaJSON)
		bulkBody.WriteString("\n")
		bulkBody.Write(place.MarshalJSON())
		bulkBody.WriteString("\n")
	}

	if bulkBody.Len() != 0 {
		res, err := client.Bulk(
			strings.NewReader(bulkBody.String()),
			client.Bulk.WithIndex("places"),
		)
		if err != nil {
			log.Fatal(err)
		}
		if res.IsError() {
			log.Println(res.String())
		}
	}

	if _, ok := <-placeCh; ok {
		wg.Add(1)
		go bulkRequest(client, placeCh, wg)
	}
}
