#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "bytebuffer.h"

int main() {
	unsigned char *test_get1, *test_get2 ;
	struct bytebuffer bb1, bb2, bb3, bb4 ;
	unsigned char sample1[] = { '0', '1', '2', '3' } ;
	unsigned char sample2[] = { 'a', 'b', 'c', 'd', 'e' } ;

	printf("Allocating 10 bytes in bytebuffer.\n") ;
	bb1 = allocate_bytebuffer(10) ;
	assert(bb1.buffersize == 10) ;

	printf("Creating bytebuffer.\n") ;
	bb2 = create_bytebuffer(4, sample1) ;
	assert(bb2.buffersize == 4) ;
	assert(get_byte(bb2, 0) == '0') ;

	printf("Wrapping bytebuffer.\n") ;
	bb3 = wrap_bytebuffer(5, sample2) ;
	assert(get_byte(bb3, 3) == 'd') ;
	put_byte(bb3, 2, 'm') ;
	assert(sample2[2] == 'm') ;

	printf("Duplicating bytebuffer.\n") ;
	bb4 = duplicate_bytebuffer(bb1) ;
	put_bytes_bulk(bb1, 0, 4, sample1) ;
	assert(get_byte(bb4, 1) == '1') ;

	printf("Getting bytes in bulk.\n") ;
	test_get1 = get_bytes_bulk(bb1) ;
	assert(test_get1[0] == '0') ;
	assert(test_get1[3] == '3') ;

	printf("Getting bytes in bulk relatively.\n") ;
	test_get2 = get_bytes_bulk_relative(bb3, 2, 3) ;
	assert(test_get2[1] == 'd') ;

	printf("Putting bytes in bulk relatively.\n") ;
	put_bytes_bulk_relative(bb1, test_get1, 3, 1, 3) ;
	assert(get_byte(bb1, 3) == '1') ;
	assert(get_byte(bb4, 4) == '2') ;

	printf("Deleting bytebuffer.\n") ;
	delete_bytebuffer(&bb2) ;
	assert(bb2.buffer == NULL) ;

	return 0 ;
}
