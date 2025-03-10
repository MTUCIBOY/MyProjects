package db

import (
	"encoding/json"
	"errors"
	"html/template"
	"log"
	"net/http"
	"strconv"
	"strings"
	"time"

	"github.com/elastic/go-elasticsearch/v8"
)

type Store interface {
	// returns a list of items, a total number of hits and (or) an error in case of one
	GetPlaces(limit int, offset int) ([]Place, int, error)
	GetRecommendationByLoc(lat, lon float64) []Place
}

type ElasticSearchStore struct {
	client *elasticsearch.Client
}

func (d *ElasticSearchStore) NewESClient() error {
	var err error
	if d.client == nil {
		log.Println("Creating new ES client ... ")
		d.client, err = elasticsearch.NewDefaultClient()
	}
	return err
}

func (d *ElasticSearchStore) UpCSVDataBase() {
	deleteIndexPlaces(d.client)
	createNewPlacesIndex(d.client)
	addDBinES(d.client)
	d.maxResWin()
}

func (d *ElasticSearchStore) GetPlaces(limit int, offset int) ([]Place, int, error) {
	var err error
	res, err := d.client.Search(
		d.client.Search.WithIndex("places"),
		d.client.Search.WithFrom(offset),
		d.client.Search.WithSize(limit),
		d.client.Search.WithBody(strings.NewReader(`{
        "track_total_hits": true
    }`)),
	)
	if err != nil {
		return nil, 0, err
	}
	defer res.Body.Close()
	if res.IsError() {
		return nil, 0, errors.New("not found")
	}

	var result map[string]interface{}
	if err := json.NewDecoder(res.Body).Decode(&result); err != nil {
		return nil, 0, err
	}

	total := result["hits"].(map[string]interface{})["total"].(map[string]interface{})["value"]
	totalNum := int(total.(float64))

	hits := result["hits"].(map[string]interface{})["hits"].([]interface{})
	var places []Place
	for _, hit := range hits {
		source := hit.(map[string]interface{})["_source"]
		jsonData, err := json.Marshal(source)
		if err != nil {
			return nil, 0, err
		}

		var place Place
		if err := json.Unmarshal(jsonData, &place); err != nil {
			return nil, 0, err
		}

		places = append(places, place)
	}

	return places, totalNum, nil
}

func (d *ElasticSearchStore) maxResWin() {
	res, err := d.client.Indices.PutSettings(strings.NewReader(`{
			"index": {
				"max_result_window": 20000
			}
		}`),
		d.client.Indices.PutSettings.WithIndex("places"),
	)
	if err != nil {
		log.Fatal(err)
	}
	if res.IsError() {
		log.Fatal(res.String())
	}
}

func UpSite() {
	var d ElasticSearchStore
	err := d.NewESClient()
	if err != nil {
		log.Fatal(err)
	}
	d.UpCSVDataBase()
	time.Sleep(time.Millisecond * 1000)
	upLocalSite(Store(&d))

	http.ListenAndServe("localhost:8888", nil)
}

func upLocalSite(s Store) {
	funcMap := template.FuncMap{
		"add": func(a, b int) int {
			return a + b
		},
		"sub": func(a, b int) int {
			return a - b
		},
	}

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		t, err := template.New("body.html").
			Funcs(funcMap).ParseFiles("../ex01/html/body.html")
		if err != nil {
			log.Fatal(err)
		}

		idPage := r.URL.Query().Get("page")
		if idPage == "" {
			idPage = "0"
		}
		idPageInt, err := strconv.Atoi(idPage)
		if err != nil {
			http.Error(
				w, "Invalid 'page' value: must be a number",
				http.StatusBadRequest,
			)
			return
		}

		p, total, err := s.GetPlaces(9, idPageInt*9)
		if idPageInt < 0 || idPageInt > total/9 {
			http.Error(
				w, "Invalid 'page' value: 'foo'.",
				http.StatusBadRequest,
			)
			return
		}
		if err != nil {
			http.Error(w, "Internal Server Error", http.StatusInternalServerError)
			return
		}

		data := struct {
			Places    []Place
			Page      int
			Total     int
			TotalPage int
		}{
			Places:    p,
			Page:      idPageInt,
			Total:     total,
			TotalPage: total / 9,
		}

		t.ExecuteTemplate(w, "body", data)
	})
}
