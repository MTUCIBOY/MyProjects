package source

import (
	"errors"
	"unsafe"
)

func getElement(arr []int, idx int) (int, error) {
	if len(arr) == 0 {
		return 0, errors.New("slice is empty")
	}
	if idx < 0 || idx >= len(arr) {
		return 0, errors.New("index out of range")
	}
	slicePointer := unsafe.Pointer(&arr[0])
	size := unsafe.Sizeof(arr[0])

	resultPointer := unsafe.Pointer(uintptr(slicePointer) + uintptr(idx)*size)

	return *(*int)(resultPointer), nil
}
