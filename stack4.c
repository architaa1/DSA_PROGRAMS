#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

int isempty(){
    if(top == -1) return 1;
    else return 0;
} 

void push(int x) {
    if (top == MAX-1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

int pop() { 
    if (top == -1)   {
        printf("Stack Underflow \n");
        return -1;
    }
    int x = stack[top--];
    return x;
}


int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+'||x == '-')
        return 1;
    else 
        return 0; 
}  

int space(char x) {
    if(x==' ' || x=='\t' || x=='\n') 
        return 1;
    else 
        return 0;
}

void infixToPostfix() {
    int i, j=0;
    char next, symbol;
    
    for(i=0;i<strlen(infix);i++) {
        symbol= infix[i];
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((next=pop())!='(')
                      postfix[j++]=next;
                    break;
                case'^':
                case'*':
                case'+':
                case'-':
                case'/':
                    while(!isempty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                    push(symbol);
                    break;
                default :
                postfix[j++] = symbol;
            
            }
        }
    }
    while(!isempty())
        postfix[j++] = pop();
	postfix[j] = '\0';
}

int power(int a,int b){
    int i,mul=1;
    for(i=0;i<b;i++){
        mul *= a;
        return mul;
    }
} 

int post_eval(){
    int i;
    int a,b;
    for(i=0;i<strlen(postfix);i++) {
        if (postfix[i]>='0'&&postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else {
            a=pop();
            b=pop();
            switch(postfix[i]){ 
                case'+':push(b+a);break;
                case'-':push(b-a);break;
                case'*':push(b*a);break;
                case'/':push(b/a);break;
                case'^':push(pow(b,a));break;
            }
        }
    }
    return pop();
}

void print(){
    int i=0;
    printf("\nPostfix Expression is:\n");
    while(postfix[i])  
       printf("%c",postfix[i++]); 
    printf("\n");
}

int main()  
{ 
    int result;
    printf("enter infix expression");
    gets(infix);
    infixToPostfix(); 
    print(); 
    result=post_eval();
    printf("\n\nresult=%d",result);
    return 0;  
}   

//7+(9-5)*2