#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int stackarr[MAX];
int top=-1;

int isfull(){
    if(top == MAX-1) return 1;
    else return 0;
}

int isempty(){
    if(top == -1) return 1;
    else return 0;
}

void push(int x) {
    if (isfull()) {
        printf("Stack overflow");
        return ;
    }
    stackarr[++top] = x;
}

int pop() {
    if (isempty()) {    
        printf("Stack underflow");
        exit(1) ;
    }   
    int data = stackarr[top--];  
    return data;
}

int peek() {
    if (isempty()) {    
        printf("Stack underflow");
        exit(1) ;
    }     
    return stackarr[top] ;
}

void print(){
    int i;
    if(top==-1){
        printf("stackoverflow");
        return;
    }
    for(i=top;i>=0;i--)
        printf("%d ",stackarr[i]);
    printf( "\n" );
}



    
                 //last element always inserted at 0th index...elements shifted right  by one position..
                 //so that the last element can be accessed easily using arr[stack_top]

int first=-1;     //first pushed index ...element where first element pushed is there

int isfull1(){
    if(first == MAX-1) return 1;
    else return 0;
}

int isempty1(){
    if(first == -1) return 1;
    else return 0;
}

void push1(int data) {
    int i;
    first+=1;
    if (isfull1()) {
        printf("Stack overflow");
        exit(1);
    }
    for(i=first;i>0;i--)      
        stackarr[i]=stackarr[i-1];
    stackarr[0] = data;    //fixed
}

int pop1() {
    int i;int value;
    if (isempty1()){        
        printf("Stack underflow");
        exit(1) ;
    }   
    value = stackarr[0];      //fixed
    for(i=0;i<first;i++)      
        stackarr[i]=stackarr[i+1];
        first -= 1;             
    return value;
}

int peek1() {
    if (isempty1()) {    
        printf("Stack underflow");
        exit(1) ;
    }     
    return stackarr[0] ;
}

             //printing prime factors of a number in descending oreder. pushed ascending popped descending
void prime_fac(int num){
    int i=2;
    while(num!=1) {
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    while(!isempty()){
        printf("%d\n",pop());
    }
}

void bin_dec(int n) {
    while(n!=0){
        push(n % 2);
        n /= 2;
    }
    if(isempty()){
         printf("Stack underflow");
        exit(1) ;
        
    }
    while(top!=-1){
        printf("%d",pop());
    }
}               

void print1(){
    int i;
    if(first==-1){
        printf("stackoverflow");
        return;
    }
    for(i=0;i<=first;i++)
        printf("%d ",stackarr[i]);
    printf( "\n" );
}

                                 

int main(){
    // push1(1);
    // push1(2);
    // push1(3);
    // pop1(); 
    // peek1(); printf("%d\n",peek1());
    // print1();
    // // push(1);
    // // push(2);
    // // push(3);
    // // push(4);
    // // int data;
    // // data=pop();
    // // data=pop();
    // // print();
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
    //     //push(data);
    //     push1(data);
    //     break;

    //     case 2:
    //     //data=pop();
    //     data=pop1();
    //     printf("popped element is %d \n",data);
    //     break;
        
    //     case 3:
    //     //printf("Topmost element is %d \n",peek());
    //     printf("Topmost element is %d \n",peek1());
    //     break;

    //     case 4:
    //     //print();
    //     print1();
    //     break;

    //     case 5:
    //     exit(1);

    //     default : printf("Wrong Choice\n"); 
    //     } 
    // }
    int num;
    printf("enter no. to be factorised");
    scanf("%d",&num);
    //prime_fac(num);
    bin_dec(num);
    return 0;
}