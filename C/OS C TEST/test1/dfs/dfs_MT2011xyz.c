/* dfs_MT2011xyz.c - 
 * Source file for implementation of Depth First Search (DFS) on a 
 * graph.
 *
 * Complete code in segments marked "ADD CODE HERE".
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
		/* ADD CODE HERE */
	int **adj_mat = /* ADD CODE HERE */
	int *q = /* ADD CODE HERE */
	int *v = /* ADD CODE HERE */

	/* Assign values for the adjacency matrix using the function, 
	 * say f, given by fnptr, i.e., element at index [i][j] 
         * should be value of f(i,j); diagonal elements are 0.
	 */
	int i,j ;

	for (i = 0 ; i < n ; i++)
		adj_mat[i] = (int*)malloc(sizeof(int)*n) ;

	for (i = 0 ; i < n ; i++) {
		for (j = 0 ; j < i ; j++) {
			adj_mat[i][j] = /* ADD CODE HERE */
			adj_mat[j][i] = /* ADD CODE HERE */
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
	/* ADD CODE HERE */

	/* Deallocate memory in adjacency matrix */
	/* ADD CODE HERE */

	/* Deallocate memory for the struct */
	/* ADD CODE HERE */

	dd = NULL ;
	return ;	
}

void visitNode(struct dfs_data *dd, int curr) { 
	int col ;
	
	/* Update the visited vector for current node. */
	dd->visited[curr] = /* ADD CODE HERE */ ;

	/* Find and set the next appropriate node in the queue after 
	 * the current node; and visit the next node.
	 */
	for (col = 0 ; col < dd->size ; col++) {
		/* Check if an edge exists from node with index curr
	         * to node with index col; as well as if the node 
	         * with index col has not been visited.
	         */
		if (/* ADD CODE HERE */) {
			/* Update the queue with the next node. */
			dd->queue[++r] = col ;
			
			/* Recursively continue visiting nodes. */
			/* ADD CODE HERE */
		}
	}

	return ;
}

void implementDFS(struct dfs_data *dd, int src) {
	/* Set the global variable to the starting index of queue. */
	r = 0 ;

	/* Set the start of the queue to source node. */
	/* ADD CODE HERE */

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
	/* ADD CODE HERE */

	/* Add nodes as given in the output of the DFS. */
	for (i = 0 ; i < dd->size ; i++) {
		if (dd->visited[i] != 0) {
			sprintf(temp, "-> %d" , /* ADD CODE HERE */) ;
			strcat(ss, temp) ;
		}
	}

	strcat(ss, ".") ; 
	return ss ;
}

