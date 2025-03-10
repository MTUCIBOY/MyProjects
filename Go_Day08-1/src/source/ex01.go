package source

import (
	"fmt"
	"reflect"
	"strings"
)

type UnknownPlant struct {
	FlowerType string
	LeafType   string
	Color      int `color_scheme:"rgb"`
}

type AnotherUnknownPlant struct {
	FlowerColor int
	LeafType    string
	Height      int `unit:"inches"`
}

func DescribePlant(plant any) {
	v := reflect.ValueOf(plant)
	t := reflect.TypeOf(plant)

	if t.Kind() != reflect.Struct {
		fmt.Println("Type not struct")
		return
	}

	for i := range t.NumField() {
		fmt.Printf("%s", t.Field(i).Name)
		if t.Field(i).Tag != "" {
			tag := strings.Split(string(t.Field(i).Tag), ":")
			fmt.Printf("(%v=%v)", tag[0], strings.Trim(tag[1], `"`))
		}
		fmt.Printf(":%v\n", v.Field(i))
	}
}
