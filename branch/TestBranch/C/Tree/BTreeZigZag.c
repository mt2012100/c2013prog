#include<stdlib.h>
#include<stdio.h>
#include<math.h>

struct tree_el {
   int val;
   struct tree_el * right, * left;
};

typedef struct tree_el node;

node **createStack() {
    node **queue = (node **)malloc(sizeof(node *)*50);
    if(queue)
        return queue;
}




void ZigZaglevelOrderTraversal( node *root) {
    if(!root)
        return ;
        
    int i=-1,j=-1;
    int i1=-1,j1=-1;
    
    node **queue = createStack();
    node **queue1 = createStack();
    
    queue[++i] = root;
    //queue[i++] = dummy;
    
    node *temp;
    node **dumy;
    int leftRight = 1;
    while(1) {
    	while(i >= 0) {
		    temp = queue[i--];
		    printf("%d ", temp->val);
		    
		   if(leftRight) { 
		   
			   if(temp->right)
						queue1[++i1] = temp->right;
				    
		   		if(temp->left)
				    queue1[++i1] = temp->left;
				
		   }
		   else {
		   		
		   		if(temp->left)
				    queue1[++i1] = temp->left;
				    
				if(temp->right)
				    queue1[++i1] = temp->right;			    
				
		   }
       }//End of j-1 if statment.
       
       printf("\n");
       if(i<0 && i1>=0) {
       		dumy = queue;
       		queue = queue1;
       		queue1 = dumy;
       		i  = i1;
       		i1=-1;
       		leftRight = 1-leftRight;
       }
       else{
       	break;
       }
           
   }
    

}

void freeQueue(node **queue) {
	int i;
	for(i=0;i<49;i++) {
        free(queue[i]);
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
   printf("%d\t",tree->val);
   if(tree->right) printout(tree->right);
}


void main() {
   node * curr, * root;
   int i;

   root = NULL;
    int a[] = {40,50,20,60,49,39,19};
   for(i=0;i<=6;i++) {
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->val = a[i];
      insert(&root, curr);
   }

   printout(root);
   printf("Level order traversal\n");
   ZigZaglevelOrderTraversal(root);
}
