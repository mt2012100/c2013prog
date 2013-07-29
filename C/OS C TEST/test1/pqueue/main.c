/* main.c - 
 * Test file for implementation of priority queues using leftist heaps.
 */

#include "pqueue.h"

/* Function to throw an error message depending on given truth value. */

void weak_assert(int condition_value, char *error) {
  	if (!condition_value) 
    		printf("%s\n", error) ;
  	return ;
}

/* main includes tests of various functions */

int main() {
	char *clist1[] = {"January", "February", "March",
			"April", "May", "June", "July",
			"August", "September", "October",
			"November", "December"} ;
	char *finallist[20] ;
  	struct node *root1, *root2, *merged12 ;
	int nsize1 = 10, nsize2 = 5, i, count = 0, condition ;
  	char **list1 = (char**) malloc(nsize1*sizeof(char*)) ;
	char **list2 = (char**) malloc(nsize2*sizeof(char*)) ;

	for (i = 0 ; i < nsize1 ; i++) {
		list1[i] = (char*) malloc(100*sizeof(char)) ;
		strcpy(list1[i], clist1[i]) ;
	}
	for (i = 0 ; i < nsize2 ; i++) {
		list2[i] = (char*) malloc(100*sizeof(char)) ;
		strcpy(list2[i], clist1[i+7]) ;
	}

	root1 = read_data(list1, nsize1) ;
	weak_assert(!strcmp("January", root1->left->left->name), 
			"read_data has failed.") ;

  	root2 = read_data(list2, nsize2) ;
	merged12 = merge(root1, root2) ;
	weak_assert(merged12->rank == root1->rank, 
			"merge has failed.") ;			

	finallist[0] = del_min(&root1) ;
	weak_assert(!strcmp("April",finallist[0]), "del_min has failed.") ;

  	while (root1 != NULL) {
    		finallist[++count] = (del_min(&root1)) ;
	}
	weak_assert(!strcmp("September",finallist[count]), 
			"del_min has failed.") ;

	for (i = 0 ; i < count ; i++) {
		condition = strcmp(finallist[i], finallist[i+1]) ;
		weak_assert(condition <= 0, "heap not sorted.") ;
	}

	return 0;
}

// EOF
