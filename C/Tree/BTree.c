#include<stdlib.h>
#include<stdio.h>
#include<math.h>

struct tree_el {
   int val;
   struct tree_el * right, * left;
};

typedef struct tree_el node;

node **createQueue() {
    node **queue = (node **)malloc(sizeof(node *)*50);
    if(queue)
        return queue;
}

void freeQueue(node **queue) {
	int i=0;
	for(i=0;i<49;i++) {
        free(queue[i]);
    }
    free(queue);
}


void levelOrderTraversal( node *root) {
    if(!root)
        return ;
        
    int i=0,j=0,k=0;
    int flag =1;
    node *dummy = (node *)malloc(sizeof(node));
    dummy->left = NULL;
    dummy->right = NULL;
    dummy->val = -1;
    
    node **queue = createQueue();
    queue[i++] = root;
    queue[i++] = dummy;
    
    node *temp;
    
    while(1) {
        temp = queue[j++];
        if(temp->val != -1 && flag) {
            printf("%d ", temp->val); //print left sided tree using flag
            flag = 0;
        }    
        
        if(temp->val == -1) {
            if (i == j) // means all element of tree  has traversed.
                return ;
            
            queue[i++] = dummy;
            flag = 1;
            printf("\n");
        }
        
        if(temp->left)
            queue[i++] = temp->left;
            
        if(temp->right)
            queue[i++] = temp->right;
        }
    
    free(queue);
}
void insert(node ** tree, node * item) {
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      insert(&(*tree)->left, item);
   else if(item->val>(*tree)->val)
      insert(&(*tree)->right, item);
}

void printout(node * tree) {
   if(tree->left) printout(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) printout(tree->right);
}


void main() {
   node * curr, * root;
   int i;

   root = NULL;
    int a[] = {40,50,20,60,49,39};
   for(i=0;i< (sizeof(a)/sizeof(a[0]));i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->val = a[i];
      insert(&root, curr);
   }

   printout(root);
   printf("Level order traversal\n");
   levelOrderTraversal(root);
}
