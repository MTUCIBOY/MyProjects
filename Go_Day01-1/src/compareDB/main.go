package main

import (
	DB "Day01/DB"
	"log"
	"os"
	"strings"
)

func main() {
	var old, new DB.DBinterface
	if len(os.Args) != 5 {
		log.Fatal("invalid command. Try ./compareDB --old <filename> --new <filename>")
	}
	mCMD := DB.ParserCMD(os.Args)

	for key, value := range mCMD {
		switch {
		case key == "--old":
			if strings.Contains(value, ".json") {
				old = &DB.JsonDB{}
			} else if strings.Contains(value, ".xml") {
				old = &DB.XmlDB{}
			} else {
				log.Fatal("--old: file is not .json or .xml")
			}
			old.SetFilename(value)
			err := old.ReadFile()
			if err != nil {
				log.Fatal(err)
			}
		case key == "--new":
			if strings.Contains(value, ".json") {
				new = &DB.JsonDB{}
			} else if strings.Contains(value, ".xml") {
				new = &DB.XmlDB{}
			} else {
				log.Fatal("--new: file is not .json or .xml")
			}
			new.SetFilename(value)
			err := new.ReadFile()
			if err != nil {
				log.Fatal(err)
			}
		default:
			log.Fatal("invalid flag. Try ./compareDB --old <filename> --new <filename>")
		}
	}

	DB.CompareCakes(&old, &new)
}
