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
_bsearch(int* arr, int search, int* index, size_t size) {
	

	// if (*index >= size) {
	// 	printf("return 1 NOT_EXIST\n");
	// 	return NOT_EXIST;
	// }

	int delta = *index / 2;
	printf("idx=%d delta=%d\n", *index, delta);

	if (delta >= size) {
		printf("return 2 NOT_EXIST\n");
		return NOT_EXIST;
	}

	if (search < arr[delta]) {
		*index -= delta;
	} else if (search > arr[delta]) {
		*index += delta;
	} else {
		printf( "find search[%d]=%d\n", delta,search);
		int res = find_next(arr, size, search, delta);
		printf( "find_next[%d]=%d\n", res, arr[res] );
		return OK;
	}

	int res = _bsearch(arr, search, index, size);

	return OK;
}


int
bsearch_next(int* arr, size_t size, int search) {

	printf("-----------------\n");
	printf("find:%d\n", search);

	if (search >= arr[size-1]) {
		printf("return NOT_EXIST\n");
		return NOT_EXIST;
	}

	if (search < arr[0]) {
		printf("return NOT_EXIST\n");
		return NOT_EXIST;
	}


	int index = size / 2;
	int res = _bsearch(arr, search, &index, size);

	// if (res > 0) {

	// }

	return 0;
}