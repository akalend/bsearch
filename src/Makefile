main: bsearch.o
	gcc  -g -c -o main.o -O3 main.c
	gcc  -o test -O3 ht.o main.o

bsearch.o:
	gcc  -g -o ht.o -c  -O3  bsearch.c


clean:
	
	if [ -f test ]; then rm test; fi
	rm *.o 

