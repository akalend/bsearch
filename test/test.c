#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../src/bsearch.h"
#include "unit.h"

static void
test_check(void)
{
	header();


//              0,1,2,3,4,5,6, 7, 8,  9,  0.  1.  2.  3. 4.  5.  6.  7. 8. 9. 0 .1  2, 
	int in[] = {1,2,2,2,3,5 ,7,7, 10, 11, 12, 15, 17,17, 17, 17, 19, 21,22,23,25,27,31};

	size_t size = sizeof(in) / sizeof(in[0]);

	int res = bsearch_next((int*)&in, size, 31);


	res = bsearch_next((int*)&in, size, 27);

	
	res = bsearch_next((int*)&in, size, 7);

	is(size , 21, "size in %d", (int)size);


	res = bsearch_next((int*)&in, size, 3);

	is(res , OK, "result %d", res);


	res = bsearch_next((int*)&in, size, 11);
	is(res , OK, "result %d", res);


	res = bsearch_next((int*)&in, size, 17);
	is(res , OK, "result %d", res);

	res = bsearch_next((int*)&in, size, 31);
	is(res , OK, "result %d", res);

	res = bsearch_next((int*)&in, size, 27);
	is(res , OK, "result %d", res);


	res = bsearch_next((int*)&in, size, 1);
	is(res , OK, "result %d", res);


	res = bsearch_next((int*)&in, size, 2);
	is(res , OK, "result %d", res);

	res = bsearch_next((int*)&in, size, 0);
	is(res , OK, "result %d", res);

	footer();
}


int
main(void)
{
	// plan(10);

	test_check();

	// check_plan();
}

