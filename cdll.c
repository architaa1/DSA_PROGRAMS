#include <stdio.h>
#include<stdlib.h>
struct node{
     struct node *prev;
    int data;
    struct node *next;
}; 

struct node *createnode(int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->prev=temp; 
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node *addatbeg(struct node *tail,int data){
    struct node *newp=createnode(data);
    if (tail==NULL)
        return newp;
    else{
        struct node *temp=tail->next;
        newp->prev=tail;
        newp->next=temp;
        temp->prev=newp;
        tail->next=newp;
        return tail;
    }
      
}

struct node *addatend(struct node *tail,int data){
    struct node *newp=createnode(data);
    if (tail==NULL)
        return newp;
    else{
        struct node *temp=tail->next;
        newp->next=temp;
        newp->prev=tail;
        tail->next=newp;
        temp->prev=newp;
        tail=newp;
        return tail;
    }
      
}

struct node *addafterpos(struct node *tail,int data,int pos){
    struct node *newp=createnode(data);
    if (tail==NULL)
        return newp;
    struct node *temp=tail->next;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
        newp->prev=temp;
        newp->next=temp->next;
        temp->next->prev=newp;
        temp->next=newp;
        if (temp==tail)
            tail=tail->next;
        return tail;
    }

struct node *delfirst(struct node *tail){
    if (tail==NULL)
        return tail;
    struct node *temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
}

struct node *dellast(struct node *tail){
    struct node* temp; 
    if (tail==NULL)
        return tail;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    temp=tail->prev;
    temp->next=tail->next;
    tail->next->prev=temp;
    free(tail);
    tail=temp;
    return tail;
}

struct node *delpos(struct node *tail,int pos){
    struct node* temp=tail->next; 
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->prev; 
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    if(temp==NULL)
        tail=temp2;
    
    return tail;
}
      

int main(){
    int data=1,pos=2;
    struct node*tail;
    tail=createnode(data);
    tail=addatbeg(tail,0); 
    tail=addatend(tail,3); 
    tail=addafterpos(tail,2,pos); 
    tail=delfirst(tail);
    tail=dellast(tail);
    tail=delpos(tail,pos);
    struct node *p=tail->next;
    do{
    printf("\n%d",p->data);
    p=p->next;
    }while(p!=tail->next);
    return 0;
}