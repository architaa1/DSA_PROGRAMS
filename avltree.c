#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
    int height;
};

int  height(struct node *root)  {  
    if (root == NULL) 
        return 0;        
    return root->height;              
} 

struct node * createnode(int data)  {
    struct node * newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1; 
    return newNode;
}

int max(int a, int b) { return (a > b)? a : b;} 

int getbalancefactor(struct node *node)  {  
    if (node == NULL)  
        return 0;     
    return height(node->left) - height(node->right);        
}

struct node * rightrotate(struct node *y)  {                           
    struct node *x = y->left;                              
    struct node *B = x->right; 

    x->right = y;                                          
    y->left = B;  

    y->height = 1 + max(height(y->right), height(y->left)); 
    x->height = 1 + max(height(x->left), height(x->right));                                                               
    return x;                                  
} 

struct node * leftrotate(struct node *x)  {    
    struct node *y = x->right;              
    struct node *b = y->left;                      
                              
    y->left = x; 
    x->right = b; 

    x->height = 1 + max(height(x->right), height(x->left)); 
    y->height = 1 + max(height(y->right), height(y->left));                        
                                
    return y;                           
} 



struct node* insert(struct node*node, int data)  {
    if(node==NULL){
        return (createnode(data));
    }
    if(data < node->data )
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    // else                      ///////////////////////
    //     return node;         //////////////////////////
    node->height= 1+max(height(node->left),height(node->right));
    int bf=getbalancefactor(node);

    if(bf>1  && data<node->left->data)
        return rightrotate(node);
    if(bf<-1 && data>node->right->data)
        return leftrotate(node);
    if(bf>1 && data>node->left->data){
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    if(bf<-1&& data<node->right->data){
        node->right=rightrotate(node->right);
        return leftrotate(node);
    }   
    return node;
} 

void preorder(struct node*root) {    
    if (root != NULL){  
    printf("%d ", root->data);  
    preorder(root->left);  
    preorder(root->right);  
    }
}  

int main(){
    struct  node *root = NULL;  
    root = insert(root,1);   
    root = insert(root,2); 
    root = insert(root,4); 
    root = insert(root,5); 
    root = insert(root,6); 
    root = insert(root,3); 
    root = insert(root,1);          
    preorder(root);   
    return 0;
}