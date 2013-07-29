/* pqueue_MT2011xyz.c - 
 * Source file for implementation of priority queues using leftist heaps.
 *
 * Complete code in segments marked "ADD CODE HERE".
 */

#include "pqueue.h"

// Function Definitions

char *del_min(struct node **root) {
	/* Allocate memory for a string to copy the name in the root. */
  	char *first = /* ADD CODE HERE */
  	struct node *tmp_root;

	/* Prepare the output string (first) by copying the name to it. */
  	strcpy(first, (*root)->name);

	/* Once the root is deleted, its children need to be merged to give 
	* a new root (tmp_root). The current root is deallocated and re-assigned 
	* to the root of the merged heap.
	*/
  	tmp_root = /* ADD CODE HERE */;
  	del_node(*root);
  	(*root) = tmp_root;

  	return first ;
}

void del_node(struct node *oldnode) {
	/* Deallocate allocated memory in a node. */
	/* ADD CODE HERE */

	return ;
}

struct node *make_node(char *newname) {
	/* Allocate memory for the new node */
  	struct node *tmp_node = /* ADD CODE HERE */;

	/* Initialize the rank. */
	tmp_node->rank = 0;

	/* Copy given name to the name of the node. */
  	/* ADD CODE HERE */

	/* Initialize both children. */
  	tmp_node->left = NULL;
  	tmp_node->right = NULL;
  
	return tmp_node;
}

struct node *merge(struct node *treeA, struct node *treeB) {
  	if (treeA == NULL) 
		return treeB;
  	if (treeB == NULL) 
		return treeA;

	/* For ease of application, always keep first parameter (treeA)
	*  to be lesser than second parameter (treeB). Swap the two inputs, 
	*  if need be, to keep name of treeA lesser than name of treeB.
	*/
 	if (strcmp(treeA->name, treeB->name) > 0)
		/* ADD CODE HERE */

	/* Update right spine of treeA, depending on its current existence.
	*/
  	treeA->right = (treeA->right == NULL) ? 
		treeB : merge(treeA->right, treeB);

  	/* The right child is guaranteed not to be NULL, but
   	* we don't know that the left child is not NULL!
   	* The rank of the NULL node is taken to be -1, so it will be
   	* swapped with a childless, non-NULL node */
  	if (treeA->right->rank > (treeA->left ? treeA->left->rank : -1)) {
    		/* ADD CODE HERE */
  	}
  
	/* Update the rank of the merged tree using rank of the right child.
	*/
  	treeA->rank = (treeA->right == NULL) ? 0 : treeA->right->rank+1 ;

  	return treeA;
}

struct node* read_data(char** name_list, int size) {
	struct node *root = NULL ;
	int i ;

	/* Incrementally merge a new node with name from the list to an 
	* existing heap.
	*/
	for (i = 0 ; i < size ; i++)
		root = /* ADD CODE HERE */ ;

	return root ;
}


void swap(struct node **nodeA, struct node **nodeB) {
  	struct node *tmpnode ;

	/* Swap the contents of the pointers. */
	tmpnode = /* ADD CODE HERE */
	*nodeA = /* ADD CODE HERE */
  	*nodeB = /* ADD CODE HERE */

	return ;
}

// EOF
