#include <stdio.h>
#include<stdlib.h>
struct node{
    float coeff;
    int expo;
    struct node *next;  
};
struct node*insert(struct node*head,float co, int ex){
    struct node *temp;
    struct node *newp=malloc(sizeof(struct node));   
    newp->coeff=co;
    newp->expo=ex;
    newp->next=NULL; 

    if(head==NULL||ex>head->expo){
        newp->next=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->expo>=ex)
                  temp=temp->next;
        newp->next=temp->next;
        temp->next=newp;

    }

    return head;
}

struct node*create(struct node*head){
    int n,expo,i;
    float coeff;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter coef for term%d",i+1);
        scanf("%f",&coeff);
        printf("enter expo for term%d",i+1);
        scanf("%d",&expo);

        head=insert(head,coeff,expo);
    }
        return head;
    }

void print(struct node *head){
    if(head==NULL)
         printf("empty");
    else{
        struct node *ptr=head;
        while(ptr!=NULL){
            printf("%.1fx^%d",ptr->coeff,ptr->expo);
            ptr=ptr->next;
            if (ptr!=NULL)
                printf(" + ");  
            else
                printf("\n");
        }
    }
}


void polyadd(struct node*head1,struct node*head2){
    struct node *ptr1 = head1, *ptr2 = head2;
    struct node*head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo == ptr2->expo){
            head3= insert(head3,ptr1->coeff + ptr2->coeff , ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo){
            head3= insert(head3,ptr1->coeff , ptr1->expo);
            ptr1 = ptr1->next;
        } 
        else if(ptr2->expo > ptr1->expo){
            head3= insert(head3,ptr2->coeff , ptr2->expo);
            ptr2 = ptr2->next;
        }           
    }
    while(ptr1 != NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo) ;
        ptr1 = ptr1->next;
        }  
    while(ptr2 != NULL) {
        head3 = insert(head3, ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->next;
        }
    printf("sum =");
    print(head3);
    

}

void polymul(struct node*head1,struct node*head2){
    struct node *ptr1 = head1, *ptr2 = head2;
    struct node*head3=NULL;
    if(head1==NULL || head2==NULL){
        printf("no polynomial");
        return;

    }
    while(ptr1 != NULL) {
        while(ptr2 != NULL) {
        head3 = insert(head3, ptr1->coeff*ptr2->coeff,ptr1->expo+ptr2->expo);
        ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2=head2;
        }  
    printf("mul =");
    print(head3);

//adding like exponent terms 
    struct node *ptr3 = head3;
    struct node *temp = NULL;
    while(ptr3->next!= NULL) {
        if(ptr3->expo==ptr3->next->expo){
            temp = ptr3->next;
            ptr3->coeff = ptr3->coeff + temp->coeff;
            ptr3->next = temp->next;
            free(temp);
        }
        else{
        
        ptr3 = ptr3->next;
        }
        
    }
    printf("new mul=");
    print(head3);
}

int main(){
    struct node* head1= NULL;
    struct node* head2 = NULL;
    printf("ENTER POL1\n");
    head1=create(head1);
    print(head1);
    printf("ENTER POL2\n");
    head2=create(head2);
    print(head2);
    polyadd(head1,head2);
    polymul(head1,head2);
    return 0;
}