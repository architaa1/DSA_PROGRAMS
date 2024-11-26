#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};

struct node*addtoempty(struct node*head,int data){
    struct node *temp= malloc(sizeof(struct node)); 
    temp->prev=NULL; 
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct node*addtobeg(struct node*head,int data){
    struct node *temp= malloc(sizeof(struct node)); 
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

struct node*addatend(struct node*head,int data){
    struct node *temp,*tp;
    temp= malloc(sizeof(struct node)); 
    temp->prev=NULL; 
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}

struct node*addafterpos(struct node*head,int data,int pos){
    struct node *newp=NULL;
    struct node *temp=head;
    struct node *temp2=NULL;
    newp=addtoempty(newp,data);
    //while(pos!=1){            
    while(pos>1){            
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){
        temp->next=newp;
        newp->prev=temp;
    }
    else{
        temp2=temp->next;
        temp->next=newp;
        temp2->prev=newp;
        newp->next=temp2;
        newp->prev=temp;

    }
    return head;
}

struct node*addbeforepos(struct node*head,int data,int pos){
    struct node *newp=NULL;
    struct node *temp=head;
    struct node *temp2=NULL;
    newp=addtoempty(newp,data);       
    while(pos>3){
        temp=temp->next;
        pos--;
    }
    if(pos==1){
        head=addtobeg(head,data);
    }
    else{
        temp2=temp->next;
        temp->next=newp;
        temp2->prev=newp;
        newp->next=temp2;
        newp->prev=temp;

    }
    return head;
}

struct node*createdll(struct node*head){
    int n,data,i;
    printf("enter no. of nodes");
    scanf("%d",&n);
    if(n==0)
        return head;
    printf("enter data for node1");
    scanf("%d",&data);
    head=addtoempty(head,data);
    for(i=1;i<n;i++){
        printf("enter data for node%d",i+1);
        scanf("%d",&data);
        head=addatend(head,data);
    }
        return head;
    }

struct node*delfirst(struct node*head){
    struct node*temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
}

struct node*dellast(struct node*head){
    struct node*temp=head;
    struct node*temp2;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;    
    temp2->next=NULL;
    free(temp);
    return head;
}

struct node*delpos(struct node*head,int pos){
    struct node*temp=head;
    struct node*temp2=NULL;
    if(pos==1){
        head=delfirst(head);
        return head;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if (temp->next==NULL){
        head=dellast(head);
    }
    else{
    temp2=temp->prev;    
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
    }
    return head;
}

struct node*reverse(struct node*head){
    struct node*ptr1=head;
    struct node*ptr2=ptr1->next;    
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
}

    int main(){
                          //CREATION OF A DOUBLY LINKED LIST 
    // struct node *head= malloc(sizeof(struct node)); 
    // head->prev=NULL; 
    // head->data=1;
    // head->next=NULL;
    struct node*head=NULL;
    struct node*ptr;
    head=createdll(head);
    // int pos=3,pos1=6;
    int pos2=3;
    // head=addtoempty(head,1);
    // head=addtobeg(head,0);
    // head=addatend(head,2); 
    // head=addatend(head,5);
    // head=addafterpos(head,3,pos);
    // head=addbeforepos(head,4,pos1);
    // head=delfirst(head);
    // head=dellast(head);
    // head=delpos(head,pos2);
    head=reverse(head);
    ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}