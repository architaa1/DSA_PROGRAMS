#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;
//};


void push(int data){
    struct node *new=(struct node*)malloc(sizeof(struct node));  
    if(new==NULL) {
        printf("Stack overflow");
        exit(1) ;
    }
    new->data=data;
    new->next=NULL;

    new->next=top;          
    top=new;              
}

// struct node* push1(int data,struct node *top){
//     struct node *new=(struct node*)malloc(sizeof(struct node));  
//     if(new==NULL) {
//         printf("Stack overflow");
//         exit(1) ;
//     }
//     new->data=data;
//     new->next=NULL;

//     new->next=top;          
//     top=new;  
//     return top;
// }

void push2(int data,struct node **top){
    struct node *new=(struct node*)malloc(sizeof(struct node));  
    if(new==NULL) {
        printf("Stack overflow");
        exit(1) ;
    }
    new->data=data;
    new->next=NULL;

    new->next=*top;          
    *top=new;  
}

int isempty(){
    if (top==NULL) return 1;
    else return 0;
}

// int isempty1(struct node*top){
//     if (top==NULL) return 1;
//     else return 0;
// }

int isempty2(struct node**top){
    if (*top==NULL) return 1;
    else return 0;
}

int pop(){
        struct node*temp=top;
        if(isempty()) {
        printf("Stack underflow");
        exit(1) ;
        }
        int val= temp->data; 
        top=top->next;
        free(temp);
        temp=NULL;
        return val;   
}

// struct node* pop1(struct node *top){
//         struct node*temp;
//         if(isempty(top)) {
//         printf("Stack underflow");
//         exit(1) ;
//         }
//         temp=top;
//         top=top->next;
//         return temp;   
// }

int pop2(struct node **top){
        struct node*temp;
        int val;
        if(isempty2(top)) {
        printf("Stack underflow");
        exit(1) ;
        }
        temp=*top;
        val=temp->data;
        *top=(*top)->next;
        free(temp);
        temp=NULL;
        return val;  
}
        

int peek(){
    if(isempty()) {
        printf("Stack underflow");
        exit(1) ;
    }
    return top->data;

}

void print(){
    struct node *ptr=NULL;
    ptr=top;
    if(isempty(top)) {
        printf("Stack underflow");
        exit(1) ;
        }
    printf("stack is\n");
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

// void print1(struct node *top){
//     struct node *ptr;
//     ptr=top;
//     if(isempty(top)) {
//         printf("Stack underflow");
//         exit(1) ;
//         }
//     printf("stack is\n");
//     while(ptr){
//         printf("%d\n",ptr->data);
//         ptr=ptr->next;
//     }
// }

void print2(struct node **top){
    struct node *ptr;
    ptr=*top;
    if(isempty2(top)) {
        printf("Stack underflow");
        exit(1) ;
    }
    printf("stack is\n");
    while(ptr){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void reverse(struct node **top){
    struct node *top1=NULL;
    struct node *top2=NULL;
    while(*top!=NULL){
        push2(pop2(top),&top1);
    }
    while(top1!=NULL){
        push2(pop2(&top1),&top2);        
    }
    while(top2!=NULL){
        push2(pop2(&top2),top);        
    }
}



void palcheck (char* s){
int i=0;
while (s[i] !='X') {
push(s[i]);
i++;
}
i++;
while (s[i]){
    if (isempty() || s[i] != pop()){ 
        printf("Not a palindrome"); 
        exit(1);
    }  
    i++;
}
if(isempty())
 printf("Palindrome");
else
 printf("not Palindrome");

}

int main(){
                          //stack with ls
    // int choice,data;
    // while(1){
    //     printf("\n\nMenu:\n1.Push \n2.Pop \n3.print top element(peek) \n4.Print Stack \n5.quit\n ");
    //     printf("enter choice");
    //     scanf("%d",&choice);
    //     switch(choice)  
    //     { 
    //     case 1:
    //     printf("enter data to  be pushed : ");
    //     scanf("%d", &data);
    //     push(data);
    //     //push1(data);
    //     break;

    //     case 2:
    //     data=pop();
    //     //data=pop1();
    //     printf("popped element is %d \n",data);
    //     break;
        
    //     case 3:
    //     printf("Topmost element is %d \n",peek());
    //     //printf("Topmost element is %d \n",peek1());
    //     break;

    //     case 4:
    //     print();
    //     //print1();
    //     break;

    //     case 5:
    //     exit(1);

    //     default : printf("Wrong Choice\n"); 
    //     } 
    // }
                        //reversal step 1to 2 pass by value
    // struct node *top=NULL;
    // struct node *top1=NULL;
    // struct node *top2=NULL;
    // struct node *temp;
    // top=push1(1,top);
    // top=push1(2,top);
    // top=push1(3,top);
    // temp=pop1(top);
    // print1(top);
    // top=temp->next;
    // top1=push1(temp->data,top1);
    // temp=pop1(top);
    // top=temp->next;
    // top1=push1(temp->data,top1);
    // temp=pop1(top);
    // top=temp->next;
    // top1=push1(temp->data,top1);
    // print1(top1);
                               //complete prog of reversal but long pass by reference
    // int data;
    // struct node *top=NULL;
    // struct node *top1=NULL;
    // struct node *top2=NULL;
    // push2(1,&top);
    // push2(2,&top);
    // push2(3,&top);
    // print2(&top);
    // //pop from 1 and push in stack 2 one by one
    // data=pop2(&top);
    // push2(data,&top1);
    // data=pop2(&top);
    // push2(data,&top1);
    // data=pop2(&top);
    // push2(data,&top1);
    // print2(&top);
    // print2(&top1);
    // //stack to to 3
    // data=pop2(&top1);
    // push2(data,&top2);
    // data=pop2(&top1);
    // push2(data,&top2);
    // data=pop2(&top1);
    // push2(data,&top2);
    // print2(&top1);
    // print2(&top2);
    // //stack 3 to 1
    // data=pop2(&top2);
    // push2(data,&top);
    // data=pop2(&top2);
    // push2(data,&top);
    // data=pop2(&top2);
    // push2(data,&top);
    // print2(&top2);
    // print2(&top);
                                    //reversal program  is complete
    // struct node *top=NULL;
    // push2(1,&top);
    // push2(2,&top);
    // push2(3,&top);
    // print2(&top);
    // reverse(&top);
    // print2(&top);

                                    //PALINDROME CHECK
char s[100];
printf("Please enter the string: ");
scanf("%s", s);
palcheck(s); 

     return 0;
}