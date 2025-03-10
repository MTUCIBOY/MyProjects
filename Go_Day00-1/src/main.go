package main

import (
	"bufio"
	"errors"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var err error
	var nums []float64

	whatmode, err := begin()
	if err != nil {
		fmt.Fprintln(os.Stderr, "error in parse:", err)
		return
	} else {
		fmt.Println("Enter number sequence (to exit, enter -1):")
	}

	nums = stof(input())
	for nums[0] != -1 || len(nums) != 1 {
		for i := 0; i < 4; i++ {
			switch whatmode[i] {
			case 1:
				fmt.Println("Mean: ", mean(nums))
			case 2:
				fmt.Println("Median: ", median(nums))
			case 3:
				fmt.Println("Mode: ", mode(nums))
			case 4:
				fmt.Println("SD: ", SD(nums))
			}
		}
		fmt.Println("Enter number sequence (to exit, enter -1):")
		nums = stof(input())
	}
}

func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
	return scanner.Text()
}

func stof(str string) []float64 {
	if str == "" {
		return []float64{0}
	}

	sliceStr := strings.Fields(str)
	nums := make([]float64, len(sliceStr))
	k := len(sliceStr) - 1

	for i := len(sliceStr) - 1; i >= 0; i-- {
		switch elem, err := strconv.ParseFloat(sliceStr[i], 64); {
		case err != nil:
			fmt.Println("error in parse: " + sliceStr[i] + "\nin float64: " + err.Error())
		case elem < -100000 || elem > 100000:
			fmt.Println("error in parse: ", elem, " - The number is outside the segment")
		default:
			nums[k] = elem
			k--
		}
	}

	nums = nums[k+1:]
	if len(nums) == 0 {
		nums = append(nums, 0)
	}
	sort.Sort(sort.Float64Slice(nums))
	return nums
}

func mean(nums []float64) float64 {
	sum := 0.0
	for _, elem := range nums {
		sum += elem
	}
	return sum / float64(len(nums))
}

func median(nums []float64) float64 {
	if len(nums)%2 != 0 {
		return nums[len(nums)/2]
	} else {
		return (nums[len(nums)/2-1] + nums[len(nums)/2]) / 2.0
	}
}

func mode(nums []float64) float64 {
	numsMap := make(map[float64]int)
	count, res := 0, 0.0

	for _, elem := range nums {
		numsMap[elem]++
	}

	for key, value := range numsMap {
		if (value > count) || (value == count && key < res) {
			count = value
			res = key
		}
	}

	return res
}

func SD(nums []float64) float64 {
	numsMean := mean(nums)
	sum := 0.0

	for _, elem := range nums {
		sum += math.Pow(elem-numsMean, 2)
	}

	return math.Sqrt(sum / numsMean)
}

func begin() ([]int, error) {
	var (
		err  error
		elem int64
	)

	nums := make([]int, 4)
	fmt.Println("What you want?:")
	fmt.Println("0 - All, 1 - Mean, 2 - Median, 3 - SD, 4 - Mode")
	sliceStr := strings.Fields(input())
	if len(sliceStr) == 0 {
		sliceStr = append(sliceStr, "0")
	}

	for i := 0; i < len(sliceStr); i++ {
		switch sliceStr[i] {
		case "0":
			nums[0] = 1
			nums[1] = 2
			nums[2] = 3
			nums[3] = 4
			break
		case "1", "2", "3", "4":
			elem, err = strconv.ParseInt(sliceStr[i], 16, 64)
			if err != nil {
				break
			} else {
				nums[i] = int(elem)
			}
		default:
			err = errors.New("You MUST enter 4 numbers or 0")
		}
	}

	sort.Sort(sort.IntSlice(nums))

	for i := 0; i < 3; i++ {
		for k := 1 + i; k < 4; k++ {
			if nums[i] == nums[k] {
				nums[k] = 0
			}
		}
	}

	return nums, err
}
