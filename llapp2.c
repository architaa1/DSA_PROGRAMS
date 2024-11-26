#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* addnodebeg(struct node*head,int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=data;
    temp->next=NULL;

    temp->next=head;         
    head=temp;               
    return head;
}

struct node* create(struct node*head,int n){
    while(n!=0){
        head=addnodebeg(head,n%10);
        n=n/10;  
    }
    return head;
}

void print(struct node *head){
    if(head==NULL)
         printf("empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr->next!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}

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

struct node* push(struct node*head,int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));   
    temp->data=val;
    temp->next=head;        
    head=temp;               
    return head;
}

struct node* add(struct node*head1,struct node*head2){
    if(head2->data==0){
        return head1;
    }
    if(head1->data==0){
        return head2;
    }
    struct node *ptr1 = head1, *ptr2 = head2;
    struct node*head3=NULL;
    int sum=0,carry=0;
    while(ptr1||ptr2){
        sum=0;
        if(ptr1){
            sum+= ptr1->data;
        }
        if(ptr2){
            sum+= ptr2->data;          
        } 
        sum+=carry;
        carry=sum/10;
        sum=sum%10;
        head3=push(head3,sum);
        if(ptr1){
            ptr1= ptr1->next;
        }
        if(ptr2){
            ptr2= ptr2->next;          
        }          
    }
    if(carry){
        head3=push(head3,carry);
    }  
    return head3;
}



int main(){
    int n1,n2;
    printf("enter n1 n2\n");
    scanf("%d %d",&n1, &n2);
    printf("linked list representation of first number\n");
    struct node* head1= NULL;
    head1=create(head1,n1);
    print(head1);
    printf("\nlinked list representation of second number\n");
    struct node* head2 = NULL;
    head2=create(head2,n2);
    print(head2);
    printf("\n");
    head1=reverse(head1);
    head2=reverse(head2);
    printf("reversed lists\n");
    print(head1);
    printf("\n");
    print(head2);

    struct node* head3 = NULL;
    head3=add(head1,head2);  
    printf("\nsum is\n");
    print(head3);
    return 0;
}