testMinCoins:
	go test -v ./source/coins/minCoins_test.go ./source/coins/coins.go

testMinCoins2:
	go test -v ./source/coins/minCoins2_test.go ./source/coins/coins.go

benchMinCoins2:
	go test -bench=. -benchmem -cpuprofile=cpu.log \
	./source/coins/minCoins2_test.go ./source/coins/coins.go