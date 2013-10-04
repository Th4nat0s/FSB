all: fsbclean

force: clean fsb

fsbclean: fsb
	strip fsb

clean:
	rm fsb *.o

fsb.o: fsb.c
	gcc -O2 -Wall -c fsb.c -lpthread -lz 

fsb: fsb.o
	gcc -o fsb fsb.o -lpthread -lz
