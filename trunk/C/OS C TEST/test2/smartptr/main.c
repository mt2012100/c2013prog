#include <stdio.h>
#include "smartptr.h"

int sample( struct smart_ptr int_ptr )
{
	int value;

	value = getobject_int( int_ptr );
	ptr_release (int_ptr);
	return value ;
}

int main()
{
	struct smart_ptr ptr;
	struct smart_ptr copy1, copy2;

	int testvalue = 25;
	int value;

	ptr = ptr_create( INT_PTR );

	printf("Assigning test value %d\n", testvalue);
	setobject_int( ptr, 25 );

	value = getobject_int( ptr );
	printf("Value retrieved is %d\n", value);

	printf("Creating first copy of pointer\n");
	copy1 = copy_ptr( ptr ); 
	value = sample( copy1 );
	printf("Value retrieved is %d\n", value);

	printf("Creating second copy of pointer\n");
	copy2 = copy_ptr( ptr ); 
	value = sample( copy2 );
	printf("Value retrieved is %d\n", value);

	ptr_release( ptr );

	/* Trying to access ptr should give error now */
	value = getobject_int( ptr );
	printf("Value retrieved is %d\n", value);
	return 0 ;
}

