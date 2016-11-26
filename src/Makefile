main: bsearch.o main.o 
	gcc  -o test -O3 ht.o main.o -lm

main.o:
	gcc -c -o main.o -O3 main.c

bsearch.o:
	gcc -o ht.o -c  -O3  bsearch.c


clean:
	
	if [ -f test ]; then rm test; fi
	rm *.o 

