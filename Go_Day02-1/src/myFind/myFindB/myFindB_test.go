package myfind

import "testing"

type testData struct {
	args  []string
	want1 infoFromARGS
	want2 []string
}

func compareInfoARGS(first, second infoFromARGS) bool {
	if first.flags != second.flags && first.fileExt != second.fileExt && len(first.fileNames) != len(second.fileNames) {
		return false
	}
	for i, value := range first.fileNames {
		if value != second.fileNames[i] {
			return false
		}
	}
	return true
}

func compareARGS(first, second []string) bool {
	if len(first) != len(second) {
		return false
	}
	for i, value := range first {
		if value != second[i] {
			return false
		}
	}
	return true
}

func TestParser(t *testing.T) {
	tests := []testData{
		{
			args: []string{"./myFind"},
			want1: infoFromARGS{
				flags:     0,
				fileExt:   "",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "/foo"},
			want1: infoFromARGS{
				flags:     0,
				fileExt:   "",
				fileNames: []string{"/foo"},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-f", "/foo"},
			want1: infoFromARGS{
				flags:     1,
				fileExt:   "",
				fileNames: []string{"/foo"},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-f"},
			want1: infoFromARGS{
				flags:     1,
				fileExt:   "",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-d"},
			want1: infoFromARGS{
				flags:     2,
				fileExt:   "",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-sl"},
			want1: infoFromARGS{
				flags:     4,
				fileExt:   "",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-ext"},
			want1: infoFromARGS{
				flags:     8,
				fileExt:   "",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-ext", "go"},
			want1: infoFromARGS{
				flags:     8,
				fileExt:   ".go",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-f", "-ext", "go"},
			want1: infoFromARGS{
				flags:     FILE | EXT,
				fileExt:   ".go",
				fileNames: []string{""},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-f", "-ext", "go", "/foo"},
			want1: infoFromARGS{
				flags:     FILE | EXT,
				fileExt:   ".go",
				fileNames: []string{"/foo"},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-f", "-ext", "go", "/foo", "/foo2"},
			want1: infoFromARGS{
				flags:     FILE | EXT,
				fileExt:   ".go",
				fileNames: []string{"/foo", "/foo2"},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "-f", "-ext", "go", "/foo", "/foo2", "-f", "/foo3"},
			want1: infoFromARGS{
				flags:     FILE | EXT,
				fileExt:   ".go",
				fileNames: []string{"/foo", "/foo2"},
			},
			want2: []string{"-f", "/foo3"},
		},
		{
			args: []string{"./myFind", "/foo", "/foo2", "/foo3"},
			want1: infoFromARGS{
				flags:     0,
				fileExt:   "",
				fileNames: []string{"/foo", "/foo2", "/foo3"},
			},
			want2: nil,
		},
		{
			args: []string{"./myFind", "/foo", "-f"},
			want1: infoFromARGS{
				flags:     0,
				fileExt:   "",
				fileNames: []string{"/foo"},
			},
			want2: []string{"-f"},
		},
	}

	for _, test := range tests {
		got1, got2 := ParsingARGS(test.args)
		if !compareInfoARGS(got1, test.want1) {
			t.Errorf("parserARGS:\nInput: %v\nwant: %v\ngot: %v\n", test.args, test.want1, got1)
		}
		if !compareARGS(got2, test.want2) {
			t.Errorf("parserARGS:\nInput: %v\nwant: %v\ngot: %v\n", test.args, test.want2, got2)
		}
	}
}
