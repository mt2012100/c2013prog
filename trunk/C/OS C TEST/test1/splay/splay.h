/* splay.h - 
 * Header file for implementation of a splay tree.
 */

/* Introduction:
A splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again. It performs basic operations such as insertion, look-up and removal in O(log n) amortized time. 

All normal operations on a binary search tree are combined with one basic operation, called splaying. Splaying the tree for a certain element rearranges the tree so that the element is placed at the root of the tree. Splaying is implemented here using a top-down approach.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
   
#define MAXVAL 30000
#define MINVAL (-30000)

/* Data structure for a node in the splay tree. */
struct SplayNode {
	int Element ;
	struct SplayNode *Left ;
	struct SplayNode *Right ;
} ;

// Function declarations. //

/* Clearing a node by deallocating memory. */                 
struct SplayNode* MakeEmpty( struct SplayNode* T );

/* Finding a node containing the given value in a given tree and returning 
* the node.
*/
struct SplayNode* Find( int X, struct SplayNode* T );

/* Finding a node containing the minimum value in a given tree and returning 
* the node.
*/
struct SplayNode* FindMin( struct SplayNode* T );

/* Finding a node containing the maximum value in a given tree and returning 
* the node.
*/
struct SplayNode* FindMax( struct SplayNode* T );

/* Initialize a node by allocating memory and initializing other data. */
struct SplayNode* Initialize( void );

/* Function for inserting a given value to a red-black tree. Returns the 
 * root of the tree.
*/       
struct SplayNode* Insert( int X, struct SplayNode* T );

/* Function for removing a given value to a red-black tree. Returns the 
 * root of the tree.
*/    
struct SplayNode* Remove( int X, struct SplayNode* T );

/* Function to return the element of a node. */
int Retrieve( struct SplayNode* T );  /* Gets root item */


// EOF
