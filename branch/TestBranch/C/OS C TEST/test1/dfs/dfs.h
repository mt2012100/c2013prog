/* dfs.h - 
 * Header file for implementation of Depth First Search (DFS) on a 
 * graph.
 */

/* Introduction:
Depth-first search is a search algorithm used in graphs, where given a 
starting node, and explores a branch to the greatest extent possible before 
backtracking, i.e. going in depth, from a neighbor to the neighbor of the 
neighbor, and so on.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structure for performing DFS on a graph where:
 * adj_matrix: Adjacency matrix of the graph;
 * queue: vector which is the sorted list of indices of nodes, i.e. the 
 * 	output of DFS on the graph. Size of queue is the number of nodes 
 *	on the graph;
 * visited: vector of same size as queue -- visited[i] = 0, if node i is
 * 	included in queue, visited[i] = 1, if the node is not in queue;
 * size: number of nodes on the graph.
 */
struct dfs_data {
	int **adj_matrix ;
	int *queue ;
	int *visited ;
	int size ;
} ;

// Functions for manipulating data structure. //

/* Creating a graph of n nodes using the following:
 * fnptr: function pointer which will take two integers (i,j) and 
 * 	and return an integer 0 and 1, which will be the value of
 *	a[i][j], where a is the adjacency matrix of the graph.
*/
struct dfs_data *createData(int n, int (*fnptr)(int,int)) ;
/* Deallocating memory for the graph */
void deleteData(struct dfs_data *dd) ;

// Functions for DFS //

/* Visiting the node at index curr during DFS for graph with n nodes.
*/
void visitNode(struct dfs_data *dd, int curr) ;
/* Implement DFS starting from source node. */
void implementDFS(struct dfs_data *dd, int src) ;
/* Print the DFS result to a string. */
char* printDFS(struct dfs_data *dd) ;

