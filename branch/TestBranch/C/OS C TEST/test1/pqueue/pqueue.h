/* pqueue.h - 
 * Header file for implementation of priority queues using leftist heaps.
 */

/* Introduction:
A priority queue is a data structure in which items arrive randomly and depart
according to an ordering predicate. It is similar to a normal queue, in which
items depart in the order they arrive (first-in, first-out), and a stack, in
which items depart in the opposite of the order in which they arrive (last-in,
first-out). It can be implemented using heaps.

A heap is a binary tree in which each node precedes its two children in a total
ordering; the ordering predicate may be less-than or greater-than, as
appropriate for the particular heap. A leftist heap satisfies the additional
criterion that the rank of each left node is greater than or equal to the rank
of its right sibling, where the rank of a node is the length of its right
spine. As a result, the right spine of any node is always the shortest path to
an empty node. The name leftist heap derives from the fact that the left
subtree is usually taller than the right subtree, so a drawing of a leftist
heap tends to ``lean'' left. 
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/* Data structure for a node in a leftist heap */
struct node{
  	int rank ;
  	char *name ;
  	struct node *left, *right ;
} ;

// Function Declarations

/* Returns the first (in alphabetical order) name in the tree,
 * and deletes it, merging the two sub-trees
 * We need to pass the address of the tree root (struct node **),
 * as the tree will have a new root after running this function.
 * This function is required for creating a priority queue.
*/
char *del_min(struct node **root) ;

/* Deallocate allocated memory for a node. 
*/
void del_node(struct node *oldnode) ;

/* Create and initialize a node with name as the given name (newname).
*/
struct node *make_node(char *newname) ;

/* Merge two leftist heaps. 
*/
struct node *merge(struct node *treeA, struct node *treeB) ;

/* Read a list of names, and incrementally insert to a heap.
*/
struct node* read_data(char** name_list, int size) ;

/* Swap two nodes in a leftist heap.
*/
void swap(struct node **nodeA, struct node **nodeB) ;

// EOF
