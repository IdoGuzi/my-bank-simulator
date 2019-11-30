CC=gcc
AR=ar
FLAGs = -Wall -g

all: mybanks main

main: main.o mybanks
	$(CC) $(FLAGS) -o main main.o libmyBank.a

mybanks: libmyBank.a
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	$(CC) -fPIC $(FLAGS) -c myBank.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all mybanks

clean:
	-rm -f *.o *.a main
