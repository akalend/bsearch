
#ifndef  __BSEARCH_H_
#define  __BSEARCH_H_

#define OK 			0
#define FAIL		1


#define TRUE		1
#define FALSE		0

typedef struct  {
	uint16_t key;
} ht_element;



/**
@brief добавление данных в хеш-таблицу
@param ht*
@param key
@param value
@return HT_RETUN_CODE
Добавляются данные в хеш-таблицу. 
Функция возвращает код:
 HT_OK 		вставка прошла успешно
 HT_EXITS	данные уже были вставлены ранее
 HT_ERROR 	ошибка переполнения
*/



#endif /* __BSEARCH_H_  */