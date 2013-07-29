/* bst.h - 
 * Header file for implementation of Binary Search Tree (BST).
 */

/* Introduction:
Binary search tree is a binary tree in which each internal node x stores an 
element such that the element stored in the left subtree of  x are less than 
or equal to x and elements stored in the right subtree of x are greater than 
or equal to  x. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data structure for a node in the BST */
struct node {
	int data ;
	struct node *lesser ;
	struct node *higher ;
};

// Functions for manipulating a BST

/* Checking recursively if a given data (target) exists in the tree for which 
* the root is given. Returns 1 if the target exists, returns 0, otherwise.
*/
int lookup(struct node *root, int target) ;

/* Creating a new node. Returns the new node. */
struct node* createNode(int data) ;

/* Inserts a node in the tree with the given root (curr). The inserted node
* will contain the given data. Returns the root of the tree.
*/
struct node* insertNode(struct node *curr, int data) ;

/* Delete a node in the tree whose root (curr) is given; the data in the node
* should be the given data. Returns the root of the tree.
*/
struct node* deleteNode(struct node *curr, int data) ;

/* Given a list of integers, of given size, as data, incrementally insert nodes  
* and create a complete tree. Returns the root of the tree.
*/ 
struct node* createTree(int *data, int size) ;

/* Returns the number of nodes in the BST. */
int bstSize(struct node *curr) ;

/* Returns the depth of the BST. */
int maxDepth(struct node *curr) ;

/* Given a sum, check if there exists a path in the BST whose nodes will have 
* their data adding up to the given sum. Returns 1 if the path exists, and 0, 
* otherwise.
*/
int hasPathSum(struct node *curr, int sum) ;

/* Modify a given BST, with root (curr0, so that the roles of the left and right 
* subtrees are swapped at every node.
*/
void mirror(struct node *curr) ;

/* Given a non-empty BST (an ordered binary tree), return the node containing 
* the minimum data value found in that tree, without traversing the entire tree.
*/
struct node* minValue(struct node *curr) ;

/* Given a non-empty BST (an ordered binary tree), return node containing 
* the maximum data value found in that tree, without traversing the entire tree.
*/
struct node* maxValue(struct node *curr) ;

/* Check if given BST with root (curr) obeys the binary search tree property.
*/
int isBST(struct node *curr) ;

/* Output the in-order tree traversal as a string. */
char* printTree(struct node *curr) ;

// EOF
