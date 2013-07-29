/* rbtree.h - 
 * Header file for implementation of a red-black tree.
 */

/* Introduction:
A red–black tree is a self-balancing binary search tree where each node has
a color attribute, the value of which is either red or black. In addition to 
the requirements imposed on binary search trees, the following requirements 
apply to red–black trees:

   1. A node is either red or black.
   2. The root is black. (This rule is sometimes omitted from other
	definitions. Since the root can always be changed from red to black,
	but not necessarily vice-versa, this rule has little effect on
	analysis.)
   3. All leaves are the same color as the root.
   4. Both children of every red node are black.
   5. Every simple path from a given node to any of its descendant leaves 
	contains the same number of black nodes.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MINVAL (-10000)

/* Data structure for a node in the red-black tree. */
typedef enum ColorType {
    Red, Black
} ColorType;

struct RedBlackNode {
    int Element;
    struct RedBlackNode* Left;
    struct RedBlackNode* Right;
    ColorType Color;
};

// Function declarations. //

/* Clearing a node by deallocating memory. */         
struct RedBlackNode* MakeEmpty( struct RedBlackNode* T );

/* Finding a node containing the given value in a given tree and returning 
* the node.
*/
struct RedBlackNode* Find( int X, struct RedBlackNode* T );

/* Initialize a node by allocating memory and initializing other data. */
struct RedBlackNode* Initialize( void ); 

/* Function for inserting a given value to a red-black tree. Returns the 
 * root of the tree.
*/       
struct RedBlackNode* Insert( int X, struct RedBlackNode* T );

/* Function to return the element of a node. */
int Retrieve( struct RedBlackNode* P );        

/* Print the in-order traversal of the tree to a string output. */
char* PrintTree( struct RedBlackNode* T );

// EOF
 
