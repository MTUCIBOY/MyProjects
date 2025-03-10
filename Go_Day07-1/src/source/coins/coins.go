package coins

import (
	"sort"
)

func isInvalidSlice(slice []int) bool {
	for _, num := range slice {
		if num < 1 {

			return true
		}
	}
	return false
}

func MinCoins(val int, coins []int) []int {
	res := make([]int, 0)
	i := len(coins) - 1
	for i >= 0 {
		for val >= coins[i] {
			val -= coins[i]
			res = append(res, coins[i])
		}
		i -= 1
	}
	return res
}

func MinCoins2(val int, coins []int) []int {
	if len(coins) == 0 || val < 1 || isInvalidSlice(coins) {
		return []int{}
	}
	if !sort.IntsAreSorted(coins) {
		sort.Ints(coins)
	}

	res := make([]int, 0)
	copyVal := val
	checkVal := 0
	i := len(coins) - 1
	for i >= 0 && val != 0 {
		for val >= coins[i] {
			val -= coins[i]
			res = append(res, coins[i])
			checkVal += coins[i]
		}
		i -= 1
	}

	if checkVal != copyVal {
		res = []int{}
	}

	return res
}
