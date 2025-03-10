package backServer

/*
	#include <stdlib.h>
	#include "../ex02/cow.c"
*/
import "C"
import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"unsafe"
)

var candies = map[string]int{
	"CE": 10,
	"AA": 15,
	"NT": 17,
	"DE": 21,
	"YR": 23,
}

type RequestBody struct {
	Money      int    `json:"money"`
	CandyType  string `json:"candyType"`
	CandyCount int    `json:"candyCount"`
}

func BuyHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	body, err := io.ReadAll(r.Body)
	if err != nil {
		w.WriteHeader(http.StatusBadRequest)
		json.NewEncoder(w).Encode(map[string]interface{}{
			"error": "Error reading body request",
		})
		return
	}
	defer r.Body.Close()

	var parametersOrder RequestBody
	if err = json.Unmarshal(body, &parametersOrder); err != nil {
		w.WriteHeader(http.StatusBadRequest)
		json.NewEncoder(w).Encode(map[string]interface{}{
			"error": "Error unmarshaling request body",
		})
		return
	}
	if parametersOrder.Money < 0 {
		w.WriteHeader(http.StatusBadRequest)
		json.NewEncoder(w).Encode(map[string]interface{}{
			"error": "Money can not be negative",
		})
		return
	}
	if parametersOrder.CandyCount < 1 {
		w.WriteHeader(http.StatusBadRequest)
		json.NewEncoder(w).Encode(map[string]interface{}{
			"error": "Number of candies can not be less than 1",
		})
		return
	}
	if _, ok := candies[parametersOrder.CandyType]; !ok {
		w.WriteHeader(http.StatusBadRequest)
		json.NewEncoder(w).Encode(map[string]interface{}{
			"error": "Invalid candy type",
		})
		return
	}

	change := parametersOrder.Money -
		candies[parametersOrder.CandyType]*parametersOrder.CandyCount
	if change < 0 {
		amount := candies[parametersOrder.CandyType]*parametersOrder.CandyCount -
			parametersOrder.Money

		w.WriteHeader(http.StatusPaymentRequired)
		json.NewEncoder(w).Encode(map[string]interface{}{
			"error": fmt.Sprintf("You need %d more money!", amount),
		})
		return
	}

	//Работа с Си
	cPhrase := C.CString("Thank you!")
	defer C.free(unsafe.Pointer(cPhrase))

	cCow := C.ask_cow(cPhrase)
	defer C.free(unsafe.Pointer(cCow))

	w.WriteHeader(http.StatusCreated)
	json.NewEncoder(w).Encode(map[string]interface{}{
		"change": change,
		"thanks": C.GoString(cCow),
	})
}
