/* splay_MT2011xyz.c - 
 * Source file for implementation of a splay tree.
 *
 * Complete code in segments marked "ADD CODE HERE".
 */

#include "splay.h"

// Static variables //

/* A null red-black node. */        
static struct SplayNode* NullNode = NULL;  /* Needs initialization */

// Helper functions //

/* This function can be called only if root has a left child. 
 * Perform a rotate between a node (root) and its left child. 
 * Update heights, then return new root 
 */
static struct SplayNode* SingleRotateWithLeft( struct SplayNode* root ) {
	struct SplayNode* newroot;

	newroot = root->Left;
	root->Left = newroot->Right;
	newroot->Right = root;

	return newroot;  
}

/* This function can be called only if root has a right child.
 * Perform a rotate between a node root and its right child.
 * Update heights, then return new root.
 */
static struct SplayNode* SingleRotateWithRight( struct SplayNode* root ) {
	struct SplayNode* newroot;

	newroot = root->Right;
	root->Right = newroot->Left;
	newroot->Left = root;

	return newroot;  
}

/* Top-down splay procedure, not requiring Item to be in tree 
 */
struct SplayNode* Splay( int Item, struct SplayNode* X ) {
	static struct SplayNode Header;
	struct SplayNode *LeftTreeMax, *RightTreeMin;

	Header.Left = Header.Right = NullNode;
	LeftTreeMax = RightTreeMin = &Header;
        NullNode->Element = Item;

        while( Item != X->Element ) {
		if( Item < X->Element ) {
			if( Item < X->Left->Element )
				X = SingleRotateWithLeft( X );
			if( X->Left == NullNode )
                        	break;
                    
			/* Link right */
                    	RightTreeMin->Left = X;
                    	RightTreeMin = X;
                    	X = X->Left;
                }
                else {
			if( Item > X->Right->Element )
                        	X = SingleRotateWithRight( X );
                    	if( X->Right == NullNode )
                        	break;

                    	/* Link left */
                    	LeftTreeMax->Right = X;
                    	LeftTreeMax = X;
                    	X = X->Right;
                }
	}  

        /* Reassemble */
        LeftTreeMax->Right = X->Left;
        RightTreeMin->Left = X->Right;
        X->Left = Header.Right;
        X->Right = Header.Left;

        return X;
}

// Function definitions //
        
struct SplayNode* Initialize( void ) {
	/* Allocate for and initialize the null node. */
	if( NullNode == NULL ) {
        	NullNode = /* ADD CODE HERE */;
		/* Initialize children */
		/* ADD CODE HERE */
        }
        return NullNode;
}

struct SplayNode* MakeEmpty( struct SplayNode* T ) {
	if (T != NullNode) {
		/* Clear the children recursively. */
		/* ADD CODE HERE */
	
		/* Clear the root. */
                /* ADD CODE HERE */
	}
	return NullNode;
}

/* Find functions can use the splay function to rotate the tree such that
* the node containing the given value, becomes the root; and the root is 
* returned. 
*/
struct SplayNode* Find( int X, struct SplayNode* T ) {
            /* ADD CODE HERE */
}

struct SplayNode* FindMin( struct SplayNode* T ) {
            /* ADD CODE HERE */
}

struct SplayNode* FindMax( struct SplayNode* T ) {
            /* ADD CODE HERE */
}

struct SplayNode* Insert( int Item, struct SplayNode* T ) {
	static struct SplayNode* NewNode = NULL;

	/* Allocate memory for the new node if needed. */
	if( /* ADD CODE HERE */ ) {
		NewNode = /* ADD CODE HERE */ ;
	}
        NewNode->Element = Item;

        if( T == NullNode ) {
		/* Set T to be the new node. */
		NewNode->Left = NewNode->Right = NullNode;
                T = NewNode;
	}
	else {
		/* Rotate so that node with Item is the root. */
		T = Splay( Item, T );
		if (Item == T->Element)
			/* Already in the tree */
			/* ADD CODE HERE */
  	        else if( Item < T->Element ) {
			NewNode->Left = T->Left;
                    	NewNode->Right = T;
                    	T->Left = NullNode;
                 	T = NewNode;
                }
                else {
			NewNode->Right = T->Right;
                    	NewNode->Left = T;
                    	T->Right = NullNode;
                    	T = NewNode;
                } 
 
	}
	
	/* To ensure that the next insert will call malloc */
        NewNode = NULL;   
        return T;
}

struct SplayNode* Remove( int Item, struct SplayNode* T ) {
	struct SplayNode* NewTree;

	if( T != NullNode ) {
		T = Splay( Item, T );

		/* Check if the root is the Item */
                if( Item == T->Element ) {
			/* Located the node containing Item */
                    	if( T->Left == NullNode )
                        	NewTree = /* ADD CODE HERE */;
                    	else {
	                        NewTree = /* ADD CODE HERE */;
        	                NewTree = Splay( Item, NewTree );
        	                NewTree->Right = T->Right;
        		}
                    	free( T );
                    	T = NewTree;
		}
	}

	return T;
}

int Retrieve( struct SplayNode* T ) {
	/* ADD CODE HERE */
}

// EOF

