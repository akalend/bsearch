#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "unit.h"
#include "../src/bsearch.h"


static void
test_check(void)
{
	header();


	int in[] = {1,2,3,5 ,7,7, 10, 11, 12, 15, 17,17, 17, 19, 21,22,23,25,27,31};

	int size = sizeof(in) / sizeof(in[0]);
	
	ok(1, "****");


	is(size , 20, "size in %d", size);

	footer();
}


int
main(void)
{
	// plan(10);

	test_check();

	// check_plan();
}

