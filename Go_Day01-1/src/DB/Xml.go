package DB

import "encoding/xml"

type XmlDB struct {
	filename string
	db       recipes
}

func (x *XmlDB) ReadFile() error {
	byteValue, err := x.db.readFile(x.filename)
	if err != nil {
		return err
	}

	err = xml.Unmarshal(byteValue, &x.db)
	return err
}

func (x *XmlDB) SetFilename(filename string) {
	x.filename = filename
}

func (x *XmlDB) DB() recipes {
	return x.db
}
