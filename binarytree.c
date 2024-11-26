#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
    struct node *temp= malloc(sizeof(struct node)); 
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL; 
    return temp;
}

void preorder(struct node*root) {    
    if (root != NULL){  
    printf("%d ", root->data);  
    preorder(root->left);  
    preorder(root->right);  
    }
}  

void postorder(struct node*root) {    
    if (root != NULL){    
    postorder(root->left);  
    postorder(root->right); 
    printf("%d ", root->data); 
    }
}  

void inorder(struct node*root) {    
    if (root != NULL){    
    inorder(root->left); 
    printf("%d ", root->data);  
    inorder(root->right);   
    }
}

int bstcheck(struct node*root) {  
    static struct node *prev =NULL ;     
    if (root != NULL){    
        if(!bstcheck(root->left))                         
            return 0;       
        if (prev != NULL && root->data <= prev->data){   //  Violation of BST property
            return 0;      
        }        
        prev = root;                    
        return bstcheck(root->right);  
    }
    else return 1;
}

struct node *search(struct node*root,int key) {     
    if (root == NULL){  
        return NULL;
    }
    if (key==root->data ) {                            
        return root;                            
    } 
    else if (key < root->data) { 
        return search(root->left,key);                                                                                  
    } 
    else {                                                                                                                                             
        return search(root->right,key);                         
    }
        
}

struct node *search2(struct node*root,int key) { 
    while(root!=NULL){    
        if (key==root->data ) {                            
            return root;                            
        } 
        else if (key < root->data) { 
            root=root->left;                                                                                  
        } 
        else {                                                                                                                                             
            root=root->right;                         
        }
    }
    return NULL;
}

void insert(struct node*root , int key){
    struct node*prev=NULL;
   while(root!=NULL){  
        prev=root;
        if (key==root->data ){
            printf("The element already exists in the tree\n");
            return ;
        }
        if (key < root->data) {  
        root = root->left;                          
        }               
        else{    
            root = root->right;   
        }              
   }
   struct node*newnode=createnode(key);
   if(key<prev->data){
    prev->left=newnode;
   }
   else{
    prev->right=newnode;
   } 
}

struct node* inorderpredecessor(struct node*root){
    root=root->left; 
    while(root->right != NULL){ 
        root = root->right;
    } 
    return root;
}

struct node *deletenode(struct node*root,int value){
    if(root == NULL) 
        return NULL;
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value>root->data)
        deletenode(root->right,value);
    else if(value<root->data)
        deletenode(root->left,value);
    else{
        struct node*ipre=inorderpredecessor(root);
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;
}



int main(){
    // struct node*p=createnode(4);
    // struct node*p1=createnode(1);
    // struct node*p3=createnode(5);
    // struct node*p4=createnode(2);
    // struct node*p2=createnode(6);
    // p->left =p1 ;
    // p->right=p2;
    // p1->left=p3;
    // p1->right=p4;
    // //preorder 4-[1-5-2]-6 
    // printf("Preorder : \n");
    // preorder(p);
    // //POSTORDER [5-2-1]-6-4
    // printf("\nPostOrder:\n ");
    // postorder(p);
    //inorder [5-2-1]-4-6
    // printf("\nInorder: \n");
    // inorder(p);

    struct node*p=createnode(5);
    struct node*p1=createnode(3);
    struct node*p3=createnode(1);
    struct node*p4=createnode(4);
    struct node*p2=createnode(6);
    p->left =p1 ;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("\nInorder: \n");
    inorder(p);
    printf("\n");
    printf("%d",bstcheck(p));  //if bstcheck is 1 it is bst if 0 it is not bst

    struct node*n=search(p,3);   
    if (n==NULL) {printf("\n Element Not Found\n");}
    else{printf("\n %d Element Found\n ",n->data);}  

    struct node*n2=search2(p,3);   
    if (n2==NULL) {printf("\n Element Not Found\n");}
    else{printf("\n %d Element Found\n ",n2->data);}  

    insert(p,7);
    printf("%d\n",p->right->right->data);

    deletenode(p,3);
    inorder(p);
    return 0;
}