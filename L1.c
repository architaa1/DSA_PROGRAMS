#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
                           //wap to interchange elements-HW
                           //COUNT of nodes function(PASS HEAD POINTER)
void count(struct node *head){
    int count=0;
    if(head==NULL)
         printf("empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    printf("%d",count); 
}; 
                           //printing data or traversal function
void printdata(struct node *head){
    if(head==NULL)
         printf("empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

                        //addatbegining function
struct node* addatbeg(struct node*head,int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=data;
    temp->next=NULL;

    temp->next=head;          //******
    head=temp;                //******
    return head;

}
                        //insert at end function**
void insertatend(struct node *head, int data){
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=data;
    temp->next=NULL;                                          
    while(ptr->next!=NULL){ //agr p1 h head=ptr ka next null ni to ptr=p1 out of loop p1 ka next h temp.if p2 v h  
        ptr=ptr->next;      //to v same ...as traversing...visiting each node
    }
    ptr->next=temp;
}                      
                          //O(1) insertatend function
struct node  *insertatend2(struct node *ptr, int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=data;
    temp->next=NULL; 
    ptr->next=temp;
    return temp;
}                        
                  
                           //add at pos function
void addatpos(struct node*head,int data,int pos){
    struct node*ptr=head; 
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=data;
    temp->next=NULL; 
    pos--;
    while(pos!=1){
        ptr=ptr->next;
        pos--;
    }
    temp->next=ptr->next;                  //******
    ptr->next=temp;                        //******
}
 
                            //delete1stnode function
struct node*delete1stnode(struct node*head){
    if (head==NULL)
          printf("empty");
    else{
        struct node*temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
}

                           //delete from certain position
void delpos(struct node **head,int pos){
    struct node*previous=*head;
    struct node*current=*head;
    if(*head==NULL)
        printf("empty");
    else if(pos==1){
        *head=current->next;
        free(current);
        current=NULL;
    }
    else{
        while(pos!=1){
            previous=current;
            current=current->next;
            pos--;
        }
        previous->next=current->next;
        free(current);
        current=NULL;
    }
    

}
                           //deletelast node function using 2 pointers                  
void deletelastnode2(struct node*head){
    if(head==NULL)
        printf("empty");
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node*temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }        
}     
                            //deletelast node function using 1 pointers
void deletelastnode1(struct node*head){
    if(head==NULL)
        printf("empty");
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node*temp=head;
        struct node*temp2=head;
        while(temp->next!=NULL){
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        free(temp);
        temp=NULL;
    }        
}
                          
                          
                          //deleting list
struct node*dellist(struct node*head){
    struct node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        free(head);
        head=temp;
    }
    return head;

}

                         //reversal of a linked list
struct node*reverse(struct node*head){
    struct node*prev=NULL;
    struct node*nxt=NULL;
    while(head!=NULL){
        nxt=head->next;
        head->next=prev;
        prev=head;
        head=nxt;
    }
    head=prev;
    return head;

}

                  //insert new element in sorted singly linked list
struct node*insertin(struct node*head,int data){
    struct node*temp;
    struct node *newp=(struct node*)malloc(sizeof(struct node));   
    newp->data=data;
    newp->next=NULL; 
    int key=data;
    if(head==NULL||key<head->data){
        newp->next=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->data<key){
                  temp=temp->next;
        }
        newp->next=temp->next;
        temp->next=newp;

    }

    return head;


}


int main(){
                          //CREATION OF A LINKED LIST Three WAYS
    struct node *head= malloc(sizeof(struct node));  
    head->data=1;
    head->next=NULL;                                

    //                        //1 way using different pointer for each node
    struct node *P1= malloc(sizeof(struct node)); 
    P1->data=2;
    P1->next=NULL;
    head->next=P1;                                 

    // struct node *P2= malloc(sizeof(struct node));  
    // P2->data=3;                                    
    // P2->next=NULL;                                 
    // P1->next=P2;                                   

    // struct node *P3=malloc(sizeof(struct node));   
    // P3->data=4;                                    
    // P3->next=NULL;                                 
    // P2->next=P3; 
                       
    //                      //otherway by single pointer
    P1= malloc(sizeof(struct node));
    P1->data=3;
    P1->next=NULL;
    head->next->next=P1;

    P1= malloc(sizeof(struct node));
    P1->data=4;
    P1->next=NULL;
    head->next->next->next=P1;
                      
                        //otherway by insert at end function(best)
    insertatend(head,5);
    insertatend(head,7);
    insertatend(head,8);

    // struct node *ptr= head;  //O(1)function insertatend & while ptr!=null print...
    // ptr=insertatend2(ptr,5);
    // ptr=insertatend2(ptr,6);
    // ptr=insertatend2(ptr,7);
    // ptr=head;
    // while (ptr!=NULL){
    //     printf("%d",ptr->data);
    //     ptr=ptr->next;
    // }

    int data=0;
    head=addatbeg(head,data);
    head=insertin(head,6);
    //P1=head;
    // while (P1!=NULL){
    //     printf("%d",P1->data);
    //     P1=P1->next;
    // }


    // int data1=8,pos=3;
    // addatpos(head,data1,pos);


    // struct node*ptr=head;
    // head=delete1stnode(head);
    // ptr=head;

    // int pos1=2;
    // delpos(&head,pos1);
    // ptr=head;
    
    // deletelastnode1(head);
    // ptr=head;

    // deletelastnode2(head);
    // ptr=head;

    // // head=dellist(head);
    // // if(head==NULL)
    // //     printf("deleted successfully");
    
    // head=reverse(head);
    // ptr=head;

    printf("no. of nodes are\n");
    count(head);

    printf("\ndata in the linked list are\n");
    printdata(head);   

    return 0;
};
