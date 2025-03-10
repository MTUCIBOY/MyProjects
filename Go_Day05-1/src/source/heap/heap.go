package heap

import (
	"container/heap"
	"errors"
	"unsafe"
)

type Present struct {
	Value int
	Size  int
}

type PresentHeap []Present

func (p PresentHeap) Len() int {
	return len(p)
}

// Не LESS, а greater
func (p PresentHeap) Less(i, j int) bool {
	if p[i].Value > p[j].Value {
		return true
	} else if p[i].Value == p[j].Value {
		return p[i].Size < p[j].Size
	}
	return false
}

func (p PresentHeap) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p *PresentHeap) Push(x any) {
	*p = append(*p, x.(Present))
}

func (p *PresentHeap) Pop() any {
	element := (*p)[len(*p)-1]
	*p = (*p)[0 : len(*p)-1]
	return element
}

func GetNCoolestPresents(presents []Present, n int) ([]Present, error) {
	if n < 0 || n > len(presents) {
		return nil, errors.New("invalid n parameter")
	}

	h := &PresentHeap{}
	result := []Present{}
	heap.Init(h)
	for i := range presents {
		heap.Push(h, presents[i])
	}
	for range n {
		result = append(result, heap.Pop(h).(Present))
	}

	return result, nil
}

func GrabPresents(presents []Present, capacity int) []Present {
	size := int(unsafe.Sizeof(presents[0]))
	res, _ := GetNCoolestPresents(presents, capacity/size)
	return res
}
