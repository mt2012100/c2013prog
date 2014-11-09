/* main.c - 
 * Test file for implementation of Binary Search Tree (BST).
 */

#include "bst.h"
#include <math.h>

/* Function to throw an error message depending on given truth value. */

void weak_assert(int condition_value, char *error) {
  if (!condition_value) 
    printf("%s\n", error) ;
  return ;
}

/* main includes tests of various functions */

int main(int argc, char **argv) {
	int *data, size, i ;
	struct node *t1 ;

	size = 10 ;
	data = (int*) malloc (sizeof(int)*size) ;
	for (i = 0 ; i < size ; i++) 
		data[i] = (int)(pow(-1,i)*100*(cos(i)*sin(i))) ;

	t1 = createTree(data,size) ;
	weak_assert(!strcmp(printTree(t1), "-49 -45 -37 -26 -14 0 13 27 37 49 "), "createTree has failed.") ;
	weak_assert(isBST(t1), "isBST has failed.") ;
	weak_assert(lookup(t1, -49), "lookup has failed.") ;
	weak_assert(!lookup(t1, -13), "lookup has failed.") ;

	weak_assert(bstSize(t1) == 10, "bstSize has failed.") ;
	deleteNode(t1, 13) ;
	deleteNode(t1, -26) ;
	deleteNode(t1, -25) ;
	weak_assert(!strcmp(printTree(t1), "-49 -45 -37 -14 0 27 37 49 "), "deleteNode has failed.") ;
	weak_assert(bstSize(t1) == 8, "deleteNode has failed.") ;

	weak_assert(!hasPathSum(t1, 26), "hasPathSum has failed.") ;
	weak_assert(!hasPathSum(t1, 64), "hasPathSum has failed.") ;
	weak_assert(hasPathSum(t1, -94), "hasPathSum has failed.") ;

	mirror(t1) ;
	weak_assert(!strcmp(printTree(t1), "49 37 27 0 -14 -37 -45 -49 "), "mirror has failed.") ;
	weak_assert(!isBST(t1), "mirror has failed.") ;

	return 0 ;
}

// EOF
