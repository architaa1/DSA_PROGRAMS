#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}; 

struct node *createnode(int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node *addatbeg(struct node*tail,int data){
    struct node *newp=(struct node*)malloc(sizeof(struct node));   
    newp->data=data;
    newp->next=tail->next;
    tail->next=newp;
    return tail;
}

struct node *addatend(struct node*tail,int data){
    struct node *newp=(struct node*)malloc(sizeof(struct node));   
    newp->data=data;
    newp->next=NULL;

    newp->next=tail->next;
    tail->next=newp; 
    tail=tail->next;
    return tail;
}

struct node *addatpos(struct node*tail,int data,int pos){
    struct node *p=tail->next; 
    struct node *newp=(struct node*)malloc(sizeof(struct node));   
    newp->data=data;
    newp->next=NULL;
     while(pos>1){
        p=p->next;
        pos--;
    }
    newp->next=p->next;
    p->next=newp;
    if(p==tail){
         tail=tail->next;
    }
    return tail;
}

struct node*createcsll(struct node*tail){
    int n,data,i;
    printf("enter no. of nodes");
    scanf("%d",&n);
    if(n==0)
        return tail;
    printf("enter data for node1");
    scanf("%d",&data);
    tail=createnode(data);
    for(i=1;i<n;i++){
        printf("enter data for node%d",i+1);
        scanf("%d",&data);
        tail=addatend(tail,data);
    }
        return tail;
    }

struct node*deletefirst(struct node*tail){
        if(tail==NULL)
            return tail;
        if(tail->next==tail){
            free(tail);
            tail=NULL;
            return tail;
        }
    struct node*temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}

struct node*deletelast(struct node*tail){
        if(tail==NULL)
            return tail;
        struct node*temp=tail->next;
        if(tail->next==tail){
            free(tail);
            tail=NULL;
            return tail;
        }    
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}

struct node*deletepos(struct node*tail,int pos){
        if(tail==NULL)
            return tail;
        struct node*temp=tail->next;
        if(tail->next==tail){
            free(tail);
            tail=NULL;
            return tail;
        }    
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    struct node*temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
        tail=temp;
    free(temp2);
    temp2=NULL;
    return tail;
}

int search(struct node*tail,int element){
    struct node*temp;
    int index=0;
    if(tail==NULL)
        return -2;
    temp=tail->next;
    do{
        if (temp->data==element)
            return index;
        temp=temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;
}

int main(){
    int data=1,pos=2,count=0;
    int el=5;
    struct node*tail;
    // tail=createnode(data);
    // tail=addatbeg(tail,0);
    // tail=addatend(tail,3);
    // tail=addatpos(tail,2,pos);
    tail=createcsll(tail);
    // tail=deletefirst(tail);
    // tail=deletelast(tail);
    // tail=deletepos(tail,pos);
    struct node *p=tail->next;
    do{
    printf("\n%d",p->data);
    p=p->next;
    }while(p!=tail->next);

    int index=search(tail,el);
    if(index==-1)
        printf("not found");
    else if (index==-2)
        printf("linked list empty");
    else
        printf("%d found at %d index",el,index); 

    // while(p!=tail){
    //     count++;
    //     p=p->next;
    // }
    // count++;
    // printf("\n%d",count);

    return 0;
}