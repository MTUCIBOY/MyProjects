package db

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"strconv"
	"strings"
	"time"
)

func (d *ElasticSearchStore) GetRecommendationByLoc(lat, lon float64) []Place {
	resp, err := d.client.Search(
		d.client.Search.WithIndex("places"),
		d.client.Search.WithSize(3),
		d.client.Search.WithBody(strings.NewReader(fmt.Sprintf(`{
		"sort": [
    {
      "_geo_distance": {
        "location": {
          "lat": %f,
          "lon": %f
        },
        "order": "asc",
        "unit": "km",
        "mode": "min",
        "distance_type": "arc",
        "ignore_unmapped": true
      }
    }
		]
		}`, lat, lon))),
	)
	if err != nil {
		log.Fatal(err)
	}

	var result map[string]interface{}
	if err := json.NewDecoder(resp.Body).Decode(&result); err != nil {
		return nil
	}

	hits := result["hits"].(map[string]interface{})["hits"].([]interface{})
	var places []Place
	for _, hit := range hits {
		source := hit.(map[string]interface{})["_source"]
		jsonData, err := json.Marshal(source)
		if err != nil {
			return nil
		}

		var place Place
		if err := json.Unmarshal(jsonData, &place); err != nil {
			return nil
		}

		places = append(places, place)
	}

	return places
}

func upLocalAPISiteRec(s Store) {
	res := struct {
		Name   string  `json:"name"`
		Places []Place `json:"places"`
	}{
		Name: "Recommendation",
	}
	http.HandleFunc("/api/recommend", func(w http.ResponseWriter, r *http.Request) {
		latPage := r.URL.Query().Get("lat")
		if latPage == "" {
			latPage = "0"
		}
		lonPage := r.URL.Query().Get("lon")
		if lonPage == "" {
			lonPage = "0"
		}

		lat, err := strconv.ParseFloat(latPage, 64)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Invalid 'page' value: 'foo'\"\n}",
				http.StatusBadRequest,
			)
			return
		}
		lon, err := strconv.ParseFloat(lonPage, 64)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Invalid 'page' value: 'foo'\"\n}",
				http.StatusBadRequest,
			)
			return
		}

		res.Places = s.GetRecommendationByLoc(lat, lon)
		if res.Places == nil {
			http.Error(
				w, "{\n\t\"error\": \"Internal server error\"\n}",
				http.StatusInternalServerError,
			)
			return
		}

		jsonRespond, err := json.Marshal(res)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Internal server error\"\n}",
				http.StatusInternalServerError,
			)
			return
		}

		w.Header().Set("Content-Type", "application/json")
		w.Write(jsonRespond)
	})
}

func UpRecommendSite() {
	var d ElasticSearchStore
	if err := d.NewESClient(); err != nil {
		log.Fatal(err)
	}
	d.UpCSVDataBase()
	time.Sleep(time.Millisecond * 1000)
	upLocalAPISiteRec(Store(&d))

	http.ListenAndServe("localhost:8888", nil)
}
