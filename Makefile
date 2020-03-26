bin/servicio: bin/servicio.o 
	clang bin/servicio.o -lmicrohttpd -lm -o bin/servicio

bin/servicio.o: servicio.c
	mkdir -p bin
	clang servicio.c -c -o bin/servicio.o

