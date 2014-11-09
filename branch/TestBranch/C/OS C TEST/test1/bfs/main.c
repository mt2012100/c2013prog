/* main.c - 
 * Test file for implementation of Breadth First Search (BFS) on a 
 * graph.
 */

#include <math.h>
#include "bfs.h"

/* Function to throw an error message depending on given truth value. */

void weak_assert(int condition_value, char *error) {
  if (!condition_value) 
    printf("%s\n", error) ;
  return ;
}

/* Functions for generating adjacency matrix */

int f1(int i, int j) {
	return ((int)pow(i+j,2)+(int)pow(i*j,3))%2 ;
}

int f2(int i, int j) {
	return (i+j)%2 ;
}

int f3(int i, int j) {
	return (int)(sin(i)*tan(j)+1000)%2 ;
}

/* main includes tests of various functions */

int main(int argc, char **argv) {
	int n = 10 ;	
	struct bfs_data *bb = createData(n, &f1) ;
	weak_assert(bb->adj_matrix[9][8] == 1, "createData has failed.") ;
	implementBFS(bb, 3) ;
	weak_assert(!strcmp(printBFS(bb), "BFS: -> 3-> 0-> 1-> 2-> 4-> 5-> 6-> 7-> 8-> 9."), "implementBFS has failed.") ;
	deleteData(bb) ;

	bb = createData(n/2, &f2) ;
	weak_assert(bb->size == n/2, "createData has failed.") ;
	implementBFS(bb, 3) ;
	weak_assert(!strcmp(printBFS(bb), "BFS: -> 3-> 0-> 2-> 4-> 1."), "implementBFS has failed.") ;
	deleteData(bb) ;	

	bb = createData(2*n, &f3) ;
	implementBFS(bb, 8) ;
	weak_assert(!strcmp(printBFS(bb), "BFS: -> 8-> 1-> 2-> 3-> 4-> 6-> 9-> 12-> 14-> 15-> 17-> 5-> 11-> 18-> 7-> 10-> 13-> 16-> 19."), "implementBFS has failed.") ;

	return 0 ;
}

// EOF


