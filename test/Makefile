main: test.o bsearch.o unit.o
	gcc -o test  bsearch.o unit.o test.o -lm

test.o:
	gcc  -c -o test.o -O3 test.c

bsearch.o:
	gcc  -std=c99 -o bsearch.o -c  -O3  ../src/bsearch.c

unit.o:
	gcc  -o unit.o -c -std=c99 -O3  unit.c

clean:
	
	if [ -f test ]; then rm test; fi
	rm *.o 

run: clean main
	./test

