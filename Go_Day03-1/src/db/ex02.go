package db

import (
	"encoding/json"
	"log"
	"net/http"
	"strconv"
	"time"
)

type PlaceAPI struct {
	Name     string  `json:"name"`
	Total    int     `json:"total"`
	Places   []Place `json:"places"`
	PrevPage int     `json:"prev_page"`
	NextPage int     `json:"next_page"`
	LastPage int     `json:"last_page"`
}

func UpAPIJSONsite() {
	var d ElasticSearchStore
	err := d.NewESClient()
	if err != nil {
		log.Fatal(err)
	}
	d.UpCSVDataBase()
	time.Sleep(time.Millisecond * 1000)
	upLocalAPISite(Store(&d))

	http.ListenAndServe("localhost:8888", nil)
}

func upLocalAPISite(s Store) {
	pAPI := PlaceAPI{Name: "Places"}

	http.HandleFunc("/api/places", func(w http.ResponseWriter, r *http.Request) {
		w.Header().Set("Content-Type", "application/json")
		idPage := r.URL.Query().Get("page")
		if idPage == "" {
			idPage = "0"
		}
		idPageInt, err := strconv.Atoi(idPage)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Invalid 'page' value: 'foo'\"\n}",
				http.StatusBadRequest,
			)
			return
		}

		p, total, err := s.GetPlaces(9, idPageInt*9)
		if idPageInt < 0 || idPageInt > total/9 {
			http.Error(
				w, "{\n\t\"error\": \"Invalid 'page' value: 'foo'\"\n}",
				http.StatusBadRequest,
			)
			return
		}
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Internal server error\"\n}",
				http.StatusInternalServerError,
			)
			return
		}
		pAPI.Total = total
		pAPI.Places = p
		pAPI.PrevPage = idPageInt - 1
		pAPI.NextPage = idPageInt + 1
		pAPI.LastPage = total / 9

		jsonRespond, err := json.Marshal(pAPI)
		if err != nil {
			http.Error(
				w, "{\n\t\"error\": \"Internal server error\"\n}",
				http.StatusInternalServerError,
			)
			return
		}

		w.Write(jsonRespond)
	})
}
