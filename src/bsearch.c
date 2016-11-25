#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "bsearch.h"

inline int
find_next(int* arr, size_t size, int search, int current ) {
	while(++current < size) {
		if (arr[current] > search) return current;
	}
	return NOT_EXIST;
}

static int
_bsearch(int* arr, int search, int* index, int delta, size_t size) {
	
	// if (*index >= size) {
	// 	printf("return 1 NOT_EXIST\n");
	// 	return NOT_EXIST;
	// }

 	delta = delta / 2;

	if (!delta) {
		return NOT_EXIST;
	}

	if (delta >= size) {
		printf("return 2 NOT_EXIST\n");
		return NOT_EXIST;
	}

	if (search < arr[*index]) {
		*index -= delta;
	} else if (search > arr[*index]) {
		*index += delta;
	} else {
		printf( "find search[%d]=%d\n", delta,search);
		int res = find_next(arr, size, search, delta);
		printf( "find_next[%d]=%d\n", res, arr[res] );
		return res;
	}

	printf("[%d] idx=%d delta=%d \n", arr[*index],*index, delta);
	int res = _bsearch(arr, search, index, delta, size);

	return res;
}


int
bsearch_next(int* arr, size_t size, int search) {

	printf("-----------------\n");
	printf("find:%d\n", search);

	if (search >= arr[size-1]) {
		printf("return NOT_EXIST\n");
		return NOT_EXIST;
	}

	/*
	если поиск меньше первого элемента то выводим первыый элемент
	index = 0
	*/
	if (search < arr[0]) {
		printf("return 0\n");
		return 0;
	}


	int index = size / 2;
	int res = _bsearch(arr, search, &index, index, size);


	printf("return %d\n", res);

	return 0;
}