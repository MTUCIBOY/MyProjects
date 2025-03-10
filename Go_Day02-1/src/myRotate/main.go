package main

import (
	"archive/tar"
	"compress/gzip"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"sync"
	"time"
)

func main() {
	dir, filenames := parserARGS(os.Args)
	if dir != "" {
		os.Mkdir(dir, 0755)
		dir += "/"
	}
	var wg sync.WaitGroup
	for _, filename := range filenames {
		wg.Add(1)
		go createZip(dir, filename, &wg)
	}
	wg.Wait()
}

func parserARGS(args []string) (string, []string) {
	if len(args) < 1 {
		return "", nil
	}
	args = args[1:]
	var dir string
	filenames := make([]string, 0, len(args))
	if len(args) > 1 && args[0] == "-a" {
		dir = args[1]
		args = args[2:]
	}
	for _, filename := range args {
		filenames = append(filenames, strings.TrimSuffix(filename, ".log"))
	}
	return dir, filenames
}

func createZip(dir, filename string, wg *sync.WaitGroup) {
	defer wg.Done()
	result, err := os.Create(dir + filename + "_" + strconv.FormatInt(time.Now().Unix(), 10) + ".tar.gz")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer result.Close()

	gw := gzip.NewWriter(result)
	defer gw.Close()
	tw := tar.NewWriter(gw)
	defer tw.Close()

	if err := addFile(tw, filename+".log"); err != nil {
		fmt.Println(err)
		os.Remove(dir + filename + "_" + strconv.FormatInt(time.Now().Unix(), 10) + ".tar.gz")
	}
}

func addFile(tw *tar.Writer, filename string) error {
	file, err := os.Open(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	info, err := file.Stat()
	if err != nil {
		return err
	}

	header, err := tar.FileInfoHeader(info, info.Name())
	if err != nil {
		return err
	}
	header.Name = filename

	err = tw.WriteHeader(header)
	if err != nil {
		return err
	}

	_, err = io.Copy(tw, file)
	if err != nil {
		return err
	}
	return nil
}
