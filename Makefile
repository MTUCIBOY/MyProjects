.PHONY: clean_cloudDB

clean_cloudDB:
	@rm -rf ./CloudBase
	
cert_gen:
	mkcert -install
	mkcert localhost
	mkdir -p cert
	mv localhost* cert