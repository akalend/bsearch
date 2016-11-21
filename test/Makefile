main: bsearch.o unit.o
	gcc  -g -c -o test.o -O3 test.c
	gcc  -o test -O3 bsearch.o unit.o test.o

bsearch.o:
	gcc -g -o bsearch.o -c  -O3  ../src/bsearch.c

unit.o:
	gcc  -o unit.o -c -std=c99 -O3  unit.c



clean:
	
	if [ -f test ]; then rm test; fi
	rm *.o 

