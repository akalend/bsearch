/**
*  gcc -o test  -O3  main.c
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "bsearch.h"


inline void print_res(int* arr, int search, int res)
{
	if (res == NOT_EXIST) {
		printf("find %d\t NOT_EXIST\n",search);
	} else {
		printf("find %d\t arr[%d]=%d\n",search, res, *(arr+res));
	}
}

int 
main(int argc, char** argv )
{
	
//              0,1,2,3,4, 5,6, 7, 8,  9,  0.  1.  2.  3. 4.  5.  6.  7. 8. 9. 0 .1 
	int in[] = {1,2,2,2,5 ,7,7, 10, 11, 12, 15, 17,17, 17, 17, 19, 21,22,23,25,27,31, 40};

	size_t size = sizeof(in) / sizeof(in[0]);

	int i;
	printf("input:\n");
	for(i=0; i < size; i++) {
		printf("%02d ", i);
	}
	printf("\n");

	for(i=0; i < size; i++) {
		printf("%02d ", in[i]);
	}
	printf("\n");

	int search = 31;
	int res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 27;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);	
	
	search = 3;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);


	search = 11;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);


	search = 17;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 18;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 5;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 6;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 27;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);


	search = 29;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 1;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);


	search = 2;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 0;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = -1;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	search = 40;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);


	search = 50;
	res = bsearch_next((int*)&in, size, search);
	print_res((int*)&in, search, res);

	return EXIT_SUCCESS;
} 