package DB

import (
	"encoding/json"
	"encoding/xml"
	"errors"
	"fmt"
	"io"
	"os"
	"strings"
)

type DBinterface interface {
	ReadFile() error
	DB() recipes
	SetFilename(string)
}

type recipes struct {
	Cakes []cake `json:"cake" xml:"cake"`
}

type cake struct {
	Name            string        `json:"name" xml:"name"`
	Time            string        `json:"time" xml:"stovetime"`
	IngredientsList []ingredients `json:"ingredients" xml:"ingredients>item"`
}

type ingredients struct {
	IngredientName  string `json:"ingredient_name" xml:"itemname"`
	IngredientCount string `json:"ingredient_count" xml:"itemcount"`
	IngredientUnit  string `json:"ingredient_unit" xml:"itemunit"`
}

func (r *recipes) MakeNameMap() map[string]cake {
	result := make(map[string]cake, len(r.Cakes))
	for i, value := range r.Cakes {
		result[value.Name] = r.Cakes[i]
	}
	return result
}

func (c *cake) MakeIngredientsMap() map[string]ingredients {
	result := make(map[string]ingredients, len(c.IngredientsList))
	for i, value := range c.IngredientsList {
		result[value.IngredientName] = c.IngredientsList[i]
	}
	return result
}

func (r *recipes) readFile(filename string) ([]byte, error) {
	file, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	byteValue, err := io.ReadAll(file)
	if err != nil {
		return nil, err
	}

	return byteValue, nil
}

func GetDB(filename string) (DBinterface, error) {
	var jcake JsonDB
	var xcake XmlDB
	var interDB DBinterface

	if strings.Contains(filename, ".json") {
		jcake.SetFilename(filename)
		interDB = &jcake
	} else if strings.Contains(filename, ".xml") {
		xcake.SetFilename(filename)
		interDB = &xcake
	} else {
		return nil, errors.New("invalid file: file is not .json or .xml")
	}

	err := interDB.ReadFile()
	return interDB, err
}

func PrintDB(d DBinterface, format string) {
	if format == "xml" {
		byteV, _ := xml.MarshalIndent(d.DB(), "", "    ")
		fmt.Println(string(byteV))
	} else if format == "json" {
		byteV, _ := json.MarshalIndent(d.DB(), "", "    ")
		fmt.Println(string(byteV))
	} else {
		fmt.Println("invalid format")
	}
}

func ParserCMD(args []string) map[string]string {
	flagsAndFiles := make(map[string]string, 2)
	for i := 1; i < len(args)-1; i++ {
		if args[i][0] == '-' {
			flagsAndFiles[args[i]] = args[i+1]
		}
	}
	return flagsAndFiles
}

func CompareCakes(old *DBinterface, new *DBinterface) {
	ODB := (*old).DB()
	NDB := (*new).DB()
	mODB := ODB.MakeNameMap()
	mNDB := NDB.MakeNameMap()

	for key := range mODB {
		if _, ok := mNDB[key]; !ok {
			fmt.Printf("REMOVED cake \"%s\"\n", key)
		}
	}
	for key := range mNDB {
		if _, ok := mODB[key]; !ok {
			fmt.Printf("ADDED cake \"%s\"\n", key)
		} else {
			temp := mODB[key]
			mODBIngredients := temp.MakeIngredientsMap()
			temp = mNDB[key]
			mNDBIngredients := temp.MakeIngredientsMap()
			if mODB[key].Time != mNDB[key].Time {
				fmt.Printf("CHANGED cooking time for cake \"%s\" - \"%s\" instead of \"%s\"\n", key, mNDB[key].Time, mODB[key].Time)
			}
			compareIngredients(&mODBIngredients, &mNDBIngredients, key)
		}
	}
}

func compareIngredients(old *map[string]ingredients, new *map[string]ingredients, cakeName string) {
	for key, value := range *old {
		if _, ok := (*new)[key]; !ok {
			fmt.Printf("REMOVED ingredient \"%s\" for cake \"%s\"\n", key, cakeName)
		} else {
			if value.IngredientCount != (*new)[key].IngredientCount {
				fmt.Printf("CHANGED unit count for ingredient \"%s\" for cake \"%s\" - \"%s\" instead of \"%s\"\n", key, cakeName, (*new)[key].IngredientCount, value.IngredientCount)
			}
			switch {
			case value.IngredientUnit == "" && (*new)[key].IngredientUnit != "":
				fmt.Printf("ADDED unit \"%s\" for ingredient \"%s\" for cake \"%s\"\n", (*new)[key].IngredientUnit, value.IngredientName, cakeName)
			case value.IngredientUnit != "" && (*new)[key].IngredientUnit == "":
				fmt.Printf("REMOVED unit for ingredient \"%s\" for cake \"%s\"\n", value.IngredientName, cakeName)
			case value.IngredientUnit != (*new)[key].IngredientUnit:
				fmt.Printf("CHANGED unit for ingredient \"%s\" for cake \"%s\" - \"%s\" instead of \"%s\"\n", value.IngredientName, cakeName, (*new)[key].IngredientUnit, value.IngredientUnit)
			}
		}
	}

	for key := range *new {
		if _, ok := (*old)[key]; !ok {
			fmt.Printf("ADDED ingredient \"%s\" for cake \"%s\"\n", key, cakeName)
		}
	}
}
