/* rbtree_MT2011xyz.c - 
 * Source file for implementation of a red-black tree.
 *
 * Complete code in segments marked "ADD CODE HERE".
 */

#include "rbtree.h"

// Static variables //

/* A null red-black node. */
static struct RedBlackNode* NullNode = NULL; /* Needs initialization */

/* Variables for a node, parent, grandparent and great-grandparent. */
static struct RedBlackNode *X, *P, *GP, *GGP;

// Helper functions //

/* Recursive function to output in-order traversal of a given tree. */
static char* DoPrint(struct RedBlackNode* T) {
	if (T != NullNode) { 

		/* Initialize output string to the left child's contents. */
		char *ss = (char*)malloc(100*sizeof(char)) ;
		/* ADD CODE HERE */

		/* Add to the output string, the contents of the root. */
		char *curr = (char*)malloc(100*sizeof(char)) ;
		sprintf(curr,"-> %d", T->Element);
		/* ADD CODE HERE */

		/* Add to the output string, the contents of the right child. */
		/* ADD CODE HERE */

		return ss ;
    	}
	return "" ;
}

/* Recursive function to clear a tree. */
static struct RedBlackNode* MakeEmptyRec(struct RedBlackNode* T) {
    	if (T != NullNode) {
		/* Clear the children */
        	/* ADD CODE HERE */

		/* Clear the root. */
        	free(T);
    	}

   	return NullNode;
}

/* This function can be called only if root has a left child. Perform a rotate 
* between a node root and its left child. Update heights, then return newroot. 
*/
static struct RedBlackNode* SingleRotateWithLeft(struct RedBlackNode* root) {
	struct RedBlackNode* newroot ; 

	newroot = root->Left ;
	root->Left = newroot->Right ;	
	newroot->Right = root ;

	return newroot; 
}

/* This function can be called only if root has a right child. Perform a rotate 
* between a node root and its right child. Update heights, then return newroot. 
*/
static struct RedBlackNode* SingleRotateWithRight(struct RedBlackNode* root) {
    	struct RedBlackNode* newroot ; 

	newroot = root->Right;
	root->Right = newroot->Left;
	newroot->Left = root;

	return newroot; 
}


/* Perform a rotation at node X (whose parent is passed as a parameter). The 
 * child is deduced by examining Item.
 */
static struct RedBlackNode* Rotate(int Item, struct RedBlackNode* Parent) {

	if (Item < Parent->Element)
        	return Parent->Left = Item < Parent->Left->Element ?
			SingleRotateWithLeft(/* ADD CODE HERE */) :
			SingleRotateWithRight(/* ADD CODE HERE */);
    	else
        	return Parent->Right = Item < Parent->Right->Element ?
			SingleRotateWithLeft(/* ADD CODE HERE */) :
			SingleRotateWithRight(/* ADD CODE HERE */);
}

/* Reorient the tree using rotate operations to restore properties of red-black
* trees, e.g. balance the tree.
*/
static void HandleReorient(int Item) {
	/* Do the color flip */
	X->Color = Red; 
	X->Left->Color = /* ADD CODE HERE */
	X->Right->Color = /* ADD CODE HERE */

	/* Have to rotate */ 
	if (P->Color == Red) {
        	GP->Color = Red;
        	if ((Item < GP->Element) != (Item < P->Element))
			/* Start double rotate */
        		P = Rotate(Item, GP); 
		X = Rotate(Item, GGP);
		X->Color = Black;
    	}

	return ;
}

// Function definitions. //

struct RedBlackNode* Initialize(void) {
	struct RedBlackNode* T;

	/* Allocate for and initialize the null node. */
	if (NullNode == NULL) {
        	NullNode = /* ADD CODE HERE */
        	NullNode->Left = NullNode->Right = NullNode;
        	NullNode->Color = Black;
        	NullNode->Element = 12345;
    	}

	/* Allocate memory and create the header node */
	T = /* ADD CODE HERE */
	T->Element = MINVAL ;
	T->Left = T->Right = NullNode;
	T->Color = Black;

	return T;
}

char* PrintTree(struct RedBlackNode* T) {
	return (DoPrint(T->Right));
}


struct RedBlackNode* MakeEmpty(struct RedBlackNode* T) {
	T->Right = MakeEmptyRec(T->Right);
	return T;
}

struct RedBlackNode* Find(int X, struct RedBlackNode* T) {
	if (T == NullNode)
        	return NullNode;
	
	/* If current node contains the element, return the root. Otherwise,
	* find in both children.
	*/
	if (X == T->Element)
		return T ;
	else 
	/* ADD CODE HERE */

        return T;
}

struct RedBlackNode* Insert(int Item, struct RedBlackNode* T) {
	X = P = GP = T;
	NullNode->Element = Item;

	/* Descend down the tree and balance the tree. */ 
	while (X->Element != Item) {
        	GGP = GP;
        	GP = P;
		P = X;

        	if (Item < X->Element)
			X = X->Left;
		else
			X = X->Right;

		/* Check if the color of the children violate the property
		* of red-black trees. If so, then re-orient the tree.
		*/
		if (X->Left->Color == Red && X->Right->Color == Red) {
            		HandleReorient(Item) ;
			T->Right->Color = Black ;
		}
    	}

	/* Check for duplicates. */
	if (X != NullNode)
        	return NullNode; 

	/* Create a new node for X. */
	X = Initialize() ;
	X->Element = Item ;

	/* Attach X to its parent */
	if (Item < P->Element) 
        	P->Left = X;
   	else
        	P->Right = X;

	/* Color X red; maybe rotate it to balance the tree. */
	HandleReorient(Item); 
	T->Right->Color = Black ;

	return T;
}

int Retrieve(struct RedBlackNode* P) {
	/* ADD CODE HERE */
}

// EOF
