#include <stdint.h>

#ifndef  __BSEARCH_H_
#define  __BSEARCH_H_

#define OK 			0
#define NOT_EXIST	-1


#define TRUE		1
#define FALSE		0

/**
@brief двоичный поиск по упорядоченному массиву

@param int* 	массив элементов
@param size_t 	размер массива элементов
@param serch	значение элемента, которое необходимо найти
@return int   индекс следующего найденного элемента или NOT_EXIST
*/
int
bsearch_next(int* arr, size_t size, int search);



#endif /* __BSEARCH_H_  */