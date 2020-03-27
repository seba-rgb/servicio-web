bin/servicio: bin/servicio.o ../fibonacci/fibonacci.o
	clang bin/servicio.o ../fibonacci/fibonacci.o -lmicrohttpd -lm -o bin/servicio

bin/servicio.o: servicio.c
	mkdir -p bin
	clang servicio.c -c -o bin/servicio.o

../fibonacci/fibonacci.o: 
	cd ../fibonacci && make

