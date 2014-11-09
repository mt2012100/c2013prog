/* main.c - 
 * Test file for implementation of Depth First Search (DFS) on a 
 * graph.
 */

#include <math.h>
#include "dfs.h"

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
	struct dfs_data *dd = createData(n, &f1) ;
	weak_assert(dd->adj_matrix[9][8] == 1, "createData has failed.") ;
	implementDFS(dd, 3) ;
	weak_assert(!strcmp(printDFS(dd), "DFS: -> 3-> 0-> 1-> 2-> 5-> 4-> 7-> 6-> 9-> 8."), "implementDFS has failed.") ;
	deleteData(dd) ;

	dd = createData(n/2, &f2) ;
	weak_assert(dd->size == n/2, "createData has failed.") ;
	implementDFS(dd, 3) ;
	weak_assert(!strcmp(printDFS(dd), "DFS: -> 3-> 0-> 1-> 2-> 4."), "implementDFS has failed.") ;
	deleteData(dd) ;	

	dd = createData(2*n, &f3) ;
	implementDFS(dd, 8) ;
	weak_assert(!strcmp(printDFS(dd), "DFS: -> 1-> 3-> 2-> 4-> 7-> 5-> 10-> 13-> 6-> 11-> 16-> 14-> 9-> 12-> 19-> 15-> 18-> 17-> 0."), "implementDFS has failed.") ;

	return 0 ;
}
