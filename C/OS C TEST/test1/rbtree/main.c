/* main.c - 
 * Test file for implementation of a red-black tree.
 */

#include "rbtree.h"
#define N 8

/* Function to throw an error message depending on given truth value. */

void weak_assert(int condition_value, char *error) {
  	if (!condition_value) 
    		printf("%s\n", error) ;
  	return ;
}

/* main includes tests of various functions */

int main(int argc, char **argv) {
    struct RedBlackNode* T;
    struct RedBlackNode* P;
    int i;
    int j = 0;

    T = Initialize();
    T = MakeEmpty(T);

    for (i = 0; i < N; i++, j = (j + 7) % N)
        T = Insert(j, T);
    weak_assert(!strcmp("-> 0-> 1-> 2-> 3-> 4-> 5-> 6-> 7",PrintTree(T)),
		"Insert has failed.") ;

    for (i = 0; i < N; i++)
	weak_assert(!((P = Find(i, T)) == NULL || Retrieve(P) != i),
		"Find and Retrieve have failed.") ;
 
    return 0;
}

// EOF
