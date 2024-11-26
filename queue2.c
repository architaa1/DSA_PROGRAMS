#include<stdio.h>
#include<stdlib.h>

struct node *f=NULL;
struct node *r=NULL;

struct node{
    int data;
    struct node *next;
};

void enqueue(int data){
    struct node *n=(struct node*)malloc(sizeof(struct node));  
    if(n==NULL){
        printf("queue is full");
    } 
    else{
        n->data=data;
        n->next=NULL; 
        if(f==NULL) {
            f=r=n;        
        }
        else{
            r->next=n;
            r=n;
        }        
    }
}

int dequeue(){
    int val=-1;    
    struct node* ptr=f;
    if (f==NULL)
          printf("empty...");
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

void printdata(struct node *ptr){
    printf("element are\n");
    while(ptr!=NULL){ 
        printf("element %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    printf("dequeuing%d \n",dequeue());
    enqueue(10);
    enqueue(11);
    enqueue(19);
    printdata(f);
    printf("dequeuing%d \n",dequeue());
    printf("dequeuing%d \n",dequeue());
    printf("dequeuing%d \n",dequeue());
    printdata(f);

    return 0;
}