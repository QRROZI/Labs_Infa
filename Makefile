all: Laba_countries

Laba_countries: main.o func.o
	gcc -Wall main.o func.o -o Laba_countries
main.o: main.c func.h
	gcc -Wall -c main.c
func.o: func.c func.h
	gcc -Wall -c func.c

clean:
	rm -f main.o func.o Laba_countries
