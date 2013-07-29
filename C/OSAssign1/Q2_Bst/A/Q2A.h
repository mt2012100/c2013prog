
//structure of node
struct btree {
	struct btree *left;
	struct btree *right;
	int nodeNo;
	int children;
};

typedef struct btree NODE;

NODE *node;

//create binary tree node.
NODE *createNode(NODE *node,int nodeNo, int children);
