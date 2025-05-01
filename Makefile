.PHONY: clean_cloudDB cert_gen

clean_cloudDB:
	@rm -rf ./CloudBase
	
cert_gen:
	mkcert -install
	mkcert localhost
	mkdir -p cert
	mv localhost* cert

loadENV:
	@export $(cat .env | xargs)

buildDocker:
	docker build -t my-cloud-server .

upContainer:
	docker compose up