/* bfs.h - 
 * Header file for implementation of Breadth First Search (BFS) on a 
 * graph.
 */

/* Introduction:
Breadth-first search is a search algorithm used in graphs, where given a 
starting node, all the neighboring nodes are explored before other nodes are
explored.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Data structure for performing BFS on a graph where:
 * adj_matrix: Adjacency matrix of the graph;
 * queue: vector which is the sorted list of indices of nodes, i.e. the 
 * 	output of BFS on the graph. Size of queue is the number of nodes 
 *	on the graph;
 * visited: vector of same size as queue -- visited[i] = 0, if node i is
 * 	included in queue, visited[i] = 1, if the node is not in queue;
 * size: number of nodes on the graph;
 * q_size: actual size of queue.
 */
struct bfs_data {
	int **adj_matrix ;
	int *queue ;
	int *visited ;
	int size ;
	int q_size ;
} ;

// Functions for manipulating data structure. //

/* Creating a graph of n nodes using the following:
 * fnptr: function pointer which will take two integers (i,j) and 
 * 	and return an integer 0 and 1, which will be the value of
 *	a[i][j], where a is the adjacency matrix of the graph.
*/
struct bfs_data *createData(int n, int (*fnptr)(int,int)) ;
/* Deallocating memory for the graph */
void deleteData(struct bfs_data *bb) ;

// Functions for BFS //

/* Implement BFS starting from source node. */
void implementBFS(struct bfs_data *bb, int src) ;

/* Print the BFS result to a string. */
char* printBFS(struct bfs_data *bb) ;

// EOF

