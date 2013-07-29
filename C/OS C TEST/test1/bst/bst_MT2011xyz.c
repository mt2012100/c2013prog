/* bst_MT2011xyz.c - 
 * Source file for implementation of Binary Search Tree (BST).
 *
 * Complete code in segments marked "ADD CODE HERE".
 */

#include "bst.h"

int lookup(struct node *root, int target) {
	if (root == NULL)
		return 0 ;

	else if (target == root->data)
		return 1 ;

	else {
		/* Recursively look up the left and right subtrees. */
		if (target < root->data) 
			return (lookup(root->lesser,target))/* ADD CODE HERE */ ;
		else 
			return (lookup(root->higher,target))/* ADD CODE HERE */ ;
	}
}

struct node* createNode(int data) {
	/* Allocate memory for the new node. */
	struct node *nn = /* ADD CODE HERE */

	/* Initialize values for the node */
	nn -> data = data ;
	nn -> lesser = NULL ;
	nn -> higher = NULL ;

	return nn ;
}

struct node *insertNode(struct node *curr, int data) {
	if (curr == NULL)
		/* Create a new node and return it as root of a new tree */
		return (createNode(data)) ;
	else {
		if (data == curr->data)
			printf("Repeated data: %d; Ignoring.", data) ;
		else {
			/* Recursively insert nodes in the subtrees. */
			if (data < curr->data)
				curr->lesser = /* ADD CODE HERE */ 
			else 
				curr->higher = /* ADD CODE HERE */
		}
		return (curr) ;
	}
}

struct node *deleteNode(struct node *curr, int value) {
	struct node *temp ;

	if (curr == NULL)
		return NULL ;

	/* If value is contained in the root node, and if both subtrees are non-
	* empty, then move an optimum node to the current without affecting the 
	* BST structure. The best candidate for the optimum node are the maximum 
	* value of the lesser subtree or the minimum value of the higher subtree. 
	* If any of the subtrees are empty, then the root of the non-empty 
	* subtree becomes the new root.
	*/
	if (value == curr->data) {
		if (curr->lesser != NULL && curr->higher != NULL) {
			temp = /* ADD CODE HERE */
			curr->data = temp->data ;
			/* Delete the candidate node and re-assign the subtree
			* to which it belongs. 
			*/
			/* ADD CODE HERE */
		}
		else {
			temp = curr ;
			if (curr->lesser == NULL)
				curr = /* ADD CODE HERE */ ;
			else if (curr->higher == NULL)
				curr = /* ADD CODE HERE */ ;
			free(temp) ;
		}

	}
	else {
		/* Recursively remove from the subtrees. */
		if (value < curr->data)
			curr->lesser = deleteNode(curr->lesser, value) ;
		else 
			curr->higher = deleteNode(curr->higher, value) ;
	}

	return curr ;	
}

struct node* createTree(int *data, int size) {
	int i = 0 ;
	struct node *root = NULL ;
	if (data == NULL) 
		return NULL ;

	/* Incrementally insert nodes in the tree while traversing the given
	* data list.
	*/
	for (i = 0 ; i < size ; i++) 
		root = /* ADD CODE HERE */ ;
			
	return root ;
}

int bstSize(struct node *curr) {
	if (curr == NULL)
		return 0 ;
	else
		/* Add sizes of subtrees and adjust for the root. */
		return /* ADD CODE HERE */ ;
}

int maxDepth(struct node *curr) {
	int lessDepth, highDepth ;

	if (curr == NULL)
		return 0 ;
	else {
		/* Find maximum of the depths of the subtrees; and adjust for 
		* the current level.
		*/
		lessDepth = maxDepth(curr->lesser) ;
		highDepth = maxDepth(curr->higher) ;
		if (lessDepth > highDepth)
			return /* ADD CODE HERE */ ;
		else
			return /* ADD CODE HERE */ ;
	}
}

int hasPathSum(struct node *curr, int sum) {
	int subsum ;
	if (curr == NULL)
		return (sum == 0) ;
	else {
		/* Assuming the path begins at the current root; recursively
		* check in subtrees if remainder subsum exists.
		*/
		subsum = /* ADD CODE HERE */
		return (hasPathSum(curr->lesser, subsum) ||
			hasPathSum(curr->higher, subsum)) ;
	}
}

void mirror(struct node *curr) {
	struct node *temp ;
	if (curr != NULL) {
		/* Recursively mirror subtrees */
		mirror(curr->lesser) ;
		mirror(curr->higher) ;

		/* Swap the subtrees */
		/* ADD CODE HERE */
	}
	return ;
}

struct node* minValue(struct node *curr) {
  	struct node* n = curr ;

 	if (n == NULL) 
		return n ;

  	/* Descend to find the leftmost leaf. */
  	while (n->lesser != NULL) {
    		n = n->lesser;
  	}

  	return n ;
}
 
struct node* maxValue(struct node *curr) {
  	struct node* n = curr ;

 	if (n == NULL) 
		return n ;

  	/* Descend to find the rightmost leaf. */
  	while (n->higher != NULL) {
    		n = n->higher;
  	}

	return n;
} 

int isBST(struct node *curr) {
	if (curr==NULL) return 1;


	/* Check if the BST property is violated with respect to contents of 
	* either of the subtrees.
	*/
	if (curr->lesser != NULL && maxValue(curr->lesser)->data > curr->data)
		return 0 ;

	if (curr->higher != NULL && minValue(curr->higher)->data <= curr->data)
		return 0 ;

	/* Check if the subtrees are themselves BSTs.*/
	if (!isBST(curr->lesser) || !isBST(curr->higher))
    		return 0;

	/* True if above conditions have been tested successfully. */
	return 1;
}

char* printTree(struct node *curr) {
	if (curr == NULL)
		return "" ;

	/* Initialize string ss to contents of lesser subtree. */
	char *ss = (char*) malloc(100*sizeof(char)) ;
	char cs[10] ;
	/* ADD CODE HERE */
	
	/* Add contents of root. */
	sprintf(cs, "%d ", curr->data) ;
	ss = /* ADD CODE HERE */

	/* Add contents of higher subtree. */
	ss = /* ADD CODE HERE */ ;
	return ss ;
}

// EOF

  

