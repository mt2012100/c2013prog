/* dfs_solution.c - 
 * Source file for implementation of Depth First Search (DFS) on a 
 * graph.
 */

#include "dfs.h"

/* Global variable to keep track of the last element in 
 * the queue used to obtain the result of DFS.
 */
int r ;

struct dfs_data *createData(int n, int (*fnptr)(int,int)) {
	/* Allocate memory for a new dfs_data and temporary pointers
	* for adjacency matrix (adj_mat), queue (q), and visited (v).
	*/
	struct dfs_data *newdata = 
		(struct dfs_data*) malloc (sizeof(struct dfs_data)) ;
	int **adj_mat = (int**)malloc(sizeof(int*)*n) ;
	int *q = (int*)malloc(sizeof(int)*n) ;
	int *v = (int*)malloc(sizeof(int)*n) ;

	/* Assign values for the adjacency matrix using the function, 
	 * say f, given by fnptr, i.e., element at index [i][j] 
         * should be value of f(i,j); diagonal elements are 0.
	 */
	int i,j ;

	for (i = 0 ; i < n ; i++)
		adj_mat[i] = (int*)malloc(sizeof(int)*n) ;

	for (i = 0 ; i < n ; i++) {
		for (j = 0 ; j < i ; j++) {
			adj_mat[i][j] = (*fnptr)(i,j) ;
			adj_mat[j][i] = (*fnptr)(j,i) ;
		}
		adj_mat[i][i] = 0 ;
	}

	/* Assign values for the visited vector; all nodes have not
	 * been visited.
	 */
	for (i = 0 ; i < n ; i++)
		v[i] = 0 ;
	
	/* Set the variables of the struct */
	newdata -> adj_matrix = adj_mat ;
	newdata -> queue = q ;
	newdata -> size = n ;
	newdata -> visited = v ;

	return newdata ;
}

void deleteData(struct dfs_data *dd) {
	int i ;

	/* Deallocate memory in queue and visited */
	free(dd->queue) ;
	free(dd->visited) ;

	/* Deallocate memory in adjacency matrix */
	for (i = 0 ; i < dd->size ; i++)
		free(dd->adj_matrix[i]) ;
	free(dd->adj_matrix) ;

	/* Deallocate memory for the struct */
	free(dd) ;

	dd = NULL ;
	return ;	
}

void visitNode(struct dfs_data *dd, int curr) { 
	int col ;
	
	/* Update the visited vector for current node. */
	dd->visited[curr] = 1 ;

	/* Find and set the next appropriate node in the queue after 
	 * the current node; and visit the next node.
	 */
	for (col = 0 ; col < dd->size ; col++) {
		/* Check if an edge exists from node with index curr
	         * to node with index col; as well as if the node 
	         * with index col has not been visited.
	         */
		if (dd->adj_matrix[curr][col] == 1 && 
			dd->visited[col] == 0) {
			/* Update the queue with the next node. */
			dd->queue[++r] = col ;
			
			/* Recursively continue visiting nodes. */
			visitNode(dd, col) ;
		}
	}

	return ;
}

void implementDFS(struct dfs_data *dd, int src) {
	/* Set the global variable to the starting index of queue. */
	r = 0 ;

	/* Set the start of the queue to source node. */
	dd->queue[r] = src ;

	/* Visit the source node. */
	visitNode(dd, src) ;
	return ;
}

char* printDFS(struct dfs_data *dd) {
	/* The output should have the following format for 3 nodes: 
	 * "DFS: -> index1-> index2-> index3." 
	 */
	char *ss = (char*) malloc (100*sizeof(char)) ;
	char temp[10] ;
	int i ;

	/* Initiate the output string ss with "DFS: ". */
	strcpy(ss, "DFS: ") ;

	/* Add nodes as given in the output of the DFS. */
	for (i = 0 ; i < dd->size ; i++) {
		if (dd->visited[i] != 0) {
			sprintf(temp, "-> %d" , dd->queue[i]) ;
			strcat(ss, temp) ;
		}
	}

	strcat(ss, ".") ; 
	return ss ;
}

