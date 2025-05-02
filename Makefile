.PHONY: clean_cloudDB cert_gen loadENV

clean_cloudDB:
	@rm -rf ./CloudBase

clean_build:
	@rm -rf ./build
	
cert_gen:
	mkcert -install
	mkcert localhost
	mkdir -p cert
	mv localhost* cert

buildDocker:
	docker build -t my-cloud-server .

upContainer:
	docker compose up

upServer: buildServer
	./build/main

buildServer:
	mkdir -p build
	go build -o ./build/ -v cmd/*.go