Given tree, convert this tree to its sum tree. Each node should have sum of left sub tree and right sub tree.

                  1
               /      \
             -2        6
           /   \      /  \ 
         3      4   1    2           


                  14 (7-2+3+6)
               /      \
             7(3+4)  3 (1+2)
           /   \      /  \ 
         3     4    1     2


int sumTree(node *root,int sum)
{

    if(!root)
        return 0;
     
       int tem1 =0
       if(root->left)
           tem1 = root->left->data;
           
       int tem2 = 0;
       
       if(root->right)
          tem2  =  root->right->data;
     
       int l1 =  sumTree(root->left,tem1);
        
       int l2  = sumTree(root->right,tem2);
        sum  += l1+l2;
        
        if(root->left || root->right)
        {
            
            root->data = l1+l2;
        }
         
         return sum;
      
}

preetigu@amazon.com


