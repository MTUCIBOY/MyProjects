package logo

import (
	"image"
	"image/color"
	"image/png"
	"log"
	"math"
	"math/rand"
	"os"
)

const (
	width  = 300
	height = 300
)

func CreateLogo() {
	freq := rand.Float64() * 3.0
	img := image.NewRGBA(image.Rect(0, 0, width, height))

	for x := range width {
		for y := range height {
			img.SetRGBA(x, y, color.RGBA{255, 255, 255, 255})
		}
	}
	for t := 0.0; t < 2*math.Pi; t += 0.01 {
		x := math.Sin(t)*100 + 150
		y := math.Sin(t*freq)*100 + 150
		img.SetRGBA(int(x), int(y), color.RGBA{0, 0, 0, 255})
	}

	file, err := os.Create("amazing_logo.png")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	if err := png.Encode(file, img); err != nil {
		log.Fatal(err)
	}
}
