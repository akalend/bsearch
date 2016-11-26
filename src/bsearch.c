#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "bsearch.h"

typedef struct  {
	int* arr;		// исходный массив
	int size;		// размер массива
	int search;		// элемент, который нужно найти
	int current;	// указатель на текущий элемент массива
	int delta;		// размер дуги поиска
} ctx_bsearch;


inline int
find_next(int* arr, size_t size, int search, int current ) 
{
	while(++current < size) {
		if (arr[current] > search) return current;
	}
	return NOT_EXIST;
}

static int
_bsearch(ctx_bsearch* ctx)
{	
	if (ctx->delta == 1){	
		return find_next(ctx->arr, ctx->size, ctx->search, ctx->current);
	}

 	int delta = (ctx->delta / 2);
 	delta = delta > 2 ? delta + 1 : delta;
 	int index = ctx->current;

	if (!delta) {
		return NOT_EXIST;
	}

	if (delta >= ctx->size) {
		return NOT_EXIST;
	}

	if (ctx->search < ctx->arr[ctx->current]) {
		ctx->current -= delta;
	} else if (ctx->search > ctx->arr[ctx->current]) {
		ctx->current += delta;
	} else {		
		int res = find_next(ctx->arr, ctx->size, ctx->search, delta);
		return res;
	}

	ctx->delta = delta;
	int res = _bsearch(ctx);

	return res;
}


int
bsearch_next(int* arr, size_t size, int search) {


	/*
	если искомый элемент больше последнего элемента, то решения нет
	*/
	if (search >= arr[size-1]) {
		return NOT_EXIST;
	}

	/*
	если искомый элемент меньше первого элемента то выводим первыый элемент
	current = 0
	*/
	if (search < arr[0]) {
		return 0;
	}

	int current = ceil(size / 2);

	ctx_bsearch ctx;

	ctx.arr = arr;
	ctx.size = size;
	ctx.search = search;
	ctx.current = current;
	ctx.delta = current;

	return _bsearch(&ctx);
}
