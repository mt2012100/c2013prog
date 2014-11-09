/* main.c - 
 * Test file for implementation of a splay tree.
 */

#include "splay.h"
#define NumItems 10

/* Function to throw an error message depending on given truth value. */

void weak_assert(int condition_value, char *error) {
  	if (!condition_value) 
    		printf("%s\n", error) ;
  	return ;
}

/* main includes tests of various functions */

int main( int argc, char **argv ) {
	struct SplayNode* T;
	int i, j = 0 ;

	T = Initialize( );
    	T = MakeEmpty( T );
    	for( i = 0; i < NumItems; i++, j = ( j + 7 ) % NumItems )
        	T = Insert( j, T );
  
	for( j = 0; j < 2; j++ )
        	for( i = 0; i < NumItems; i++ ) {
        		T = Find( i, T );
			weak_assert(Retrieve(T) == i, "Insert and Find have failed.") ;
        	}

	for( i = 0; i < NumItems; i += 2 )
        	T = Remove( i, T );

	for( i = 1; i < NumItems; i += 2 ) {
        	T = Find( i, T );
		weak_assert(Retrieve(T) == i, "Remove has failed.") ;
    	}

	for( i = 0; i < NumItems; i += 2 ) {
        	T = Find( i, T );
		weak_assert(Retrieve(T) != i, "Remove has failed.") ;
    	}

	weak_assert(Retrieve(T=FindMin(T)) == 1, "FindMin has failed.") ;
	weak_assert(Retrieve(T=FindMax(T)) == 9, "FindMax has failed.") ;

    return 0;
}

// EOF
