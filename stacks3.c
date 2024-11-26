#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
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
    stack[++top] = x;
}

int pop() {
    if (isempty()) {    
        printf("Stack underflow");
        exit(1) ;
    }   
    int data = stack[top--];  
    return data;
}

int match_char(char a,char b){
    if(a=='('&&  b==')' ) return 1;
    else if (a=='[' && b ==']') return 1;
    else if (a== '{' && b=='}') return 1;
    return 0;        
}

int balance_paranthesis(char s[]){
    int i;char temp;
    for(i=0; i<strlen(s); i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[') {
            push(s[i]);
        }
        if(s[i]==')'||s[i]=='}'||s[i]==']') {
            if(isempty()){
                printf("right  brackets are more than left\n");
                return 0;
            }
            else{
                temp=pop();
                if(!match_char(temp, s[i])){
                   printf("mismatched brackets\n");
                   return 0;
                }
            }
        }
    }
        if(isempty()){
            printf("balanced\n");
            return 1;
        }
        else{
            printf("not balanced\n");
            return 0;
        }

}


int main(){
    char expr[MAX];
    int bal;
    printf("enter algebraic expression");
    gets(expr);
    bal=balance_paranthesis(expr);
    if(bal)
       printf("valid\n");
    else
       printf("not valid\n");

    return 0;
}