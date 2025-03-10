package DB

import "encoding/json"

type JsonDB struct {
	filename string
	db       recipes
}

func (j *JsonDB) ReadFile() error {
	byteValue, err := j.db.readFile(j.filename)
	if err != nil {
		return err
	}

	err = json.Unmarshal(byteValue, &j.db)
	return err
}

func (j *JsonDB) SetFilename(filename string) {
	j.filename = filename
}

func (j *JsonDB) DB() recipes {
	return j.db
}
