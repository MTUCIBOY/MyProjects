package main

import (
	DB "Day01/DB"
	"log"
	"os"
)

func main() {
	var d DB.DBinterface
	var err error
	if len(os.Args) == 3 && os.Args[1] == "-f" {
		d, err = DB.GetDB(os.Args[2])
		if err != nil {
			log.Fatal(err)
		}
	} else {
		log.Fatal("invalid command. Enter ./DB -f <filename>")
	}
	DB.PrintDB(d, "json")
}
