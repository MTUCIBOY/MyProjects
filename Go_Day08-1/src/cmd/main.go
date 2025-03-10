package main

import (
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/widget"
)

func main() {
	a := app.New()
	w := a.NewWindow("School 21")

	w.SetContent(widget.NewLabel("School 21"))
	w.ShowAndRun()
}
