/* bfs_solution.c - 
 * Source file for implementation of Breadth First Search (BFS) on a 
 * graph.
 */

#include "bfs.h"

struct bfs_data *createData(int n, int (*fnptr)(int,int)) {
	/* Allocate memory for a new bfs_data and temporary pointers
	* for adjacency matrix (adj_mat), queue (q), and visited (v).
	*/
	struct bfs_data *newdata = 
		(struct bfs_data*) malloc (sizeof(struct bfs_data)) ;
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
	newdata -> q_size = 0 ;

	return newdata ;
}

void deleteData(struct bfs_data *bb) {
	int i ;

	/* Deallocate memory in queue and visited */
	free(bb->queue) ;
	free(bb->visited) ;

	/* Deallocate memory in adjacency matrix */
	for (i = 0 ; i < bb->size ; i++)
		free(bb->adj_matrix[i]) ;
	free(bb->adj_matrix) ;

	/* Deallocate memory for the struct */
	free(bb) ;

	return ;	
}

void implementBFS(struct bfs_data *bb, int src) {
	/* front and back are reference indices to the front and back of the 
	* queue. Only elements between front and back exist in the queue.
	*/
	int i, front, rear, root ;

	/* Set the queue to be empty */
	front = rear = 0 ;

	/* Update the visited status of the source */
	bb->visited[src] = 1 ;
	
	/* Add the source to the queue */
	bb->queue[rear++] = src ;

	while (front != rear) {	
		/* Starting from the front of the queue, find
		 * nodes with edges starting from the node 
		 * at the front of the queue.
	         */
		root = bb->queue[front] ;

		for (i = 0 ; i < bb->size ; i++)
			/* Check if nodes connected to the front 
			 * node have been visited or not.
			 */
			if (bb->adj_matrix[root][i] == 1 &&
				bb->visited[i] == 0) {
				
				/* Update the visited status of
				 * the neighboring node.
				 */
				bb->visited[i] = 1 ;

				/* Add the neighboring node to the 
				 * queue.
				 */
				bb->queue[rear++] = i ;
			}
		/* Advent the front. */
		front++ ;
	}

	bb->q_size = rear ;
	return ;
}

char* printBFS(struct bfs_data *bb) {
	/* The output should have the following format for 3 nodes: 
	 * "BFS: -> index1-> index2-> index3." 
	 */
	char *ss = (char*) malloc (100*sizeof(char)) ;
	char *temp ;
	int i ;

	/* Initiate the output string ss with "BFS: ". */
	strcpy(ss, "BFS: ") ;

	/* Add nodes as given in the output of the BFS. */
	for (i = 0 ; i < bb->q_size ; i++) {
		sprintf(temp, "-> %d" , bb->queue[i]) ;
		strcat(ss, temp) ;
	}

	strcat(ss, ".") ; 
	return ss ;
}

// EOF


