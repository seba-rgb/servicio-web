bin/servicio: bin/servicio.o ../fibonacci/fibonacci.o
	clang bin/servicio.o ../fibonacci/fibonacci.o -lmicrohttpd -lm -g -o bin/servicio

bin/servicio.o: servicio.c ../fibonacci/fibonacci.h
	mkdir -p bin
	clang servicio.c -c -g -o bin/servicio.o

../fibonacci/fibonacci.o: 
	cd ../fibonacci && make

../fibonacci/fibonacci.h: 
	cd .. && git clone git@github.com:seba-rgb/fibonacci.git
