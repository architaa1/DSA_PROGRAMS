#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q){                
    if(q->r==q->size-1 ) return 1;
    else return 0;
}

int c_isfull(struct queue *q){
    if(((q->r+1)%q->size)==q->f) return 1;
    else return 0;
}
 
int isempty(struct queue *q){               //same for c_queue
    if(q->r==q->f ) return 1;   //reuse---(f=r=-1) whenever q is empty
    else return 0;
}

void enqueue(struct queue* q,int data) {  
   if (isfull(q)){ 
       printf("Queue is full\n");   
   }       
   else {
    q->r++;
    q->arr[q->r] = data;    
   }
   printf("enqueue %d\n",data);
}

void c_enqueue(struct queue* q,int data) {  
   if (c_isfull(q)){ 
       printf("Queue is full\n");   
   }       
   else {
    q->r=(q->r+1)%q->size;
    q->arr[q->r] = data;    
   }
   printf("enqueue %d\n",data);
}

int dequeue(struct queue* q) {  
   int a=-1;
   if (isempty(q)){ 
       printf("Queue is empty\n");   
   }       
   else {
    q->f++;
    a=q->arr[q->f];
   }
   return a;
}


int c_dequeue(struct queue* q) {  
   int a=-1;
   if (isempty(q)){ 
       printf("Queue is empty\n");   
   }       
   else {
    q->f=(q->f+1)%q->size;
    a=q->arr[q->f];
   }
   return a;
}



int main(){
    // struct queue q;
    // q.size = 2;                           
    // q.f = q.r = -1 ;                                       
    // q.arr = (int*)malloc(sizeof(int)*q.size);
    // enqueue(&q,1);
    // enqueue(&q,2);
    // printf("dequeuing%d \n",dequeue(&q));               
    // printf("dequeuing%d \n",dequeue(&q));
    // enqueue(&q,3);
    // if(isempty(&q)){
    //     printf("empty");
    // }  
    //  if(isfull(&q)){
    //     printf("full");
    // }   
    
    struct queue q;
    q.size = 4;                           
    q.f = q.r = 0 ;                                       
    q.arr = (int*)malloc(sizeof(int)*q.size);
    c_enqueue(&q,1);
    c_enqueue(&q,2);
    c_enqueue(&q,3);
    c_enqueue(&q,7);
    printf("dequeuing%d \n",c_dequeue(&q));
    printf("dequeuing%d \n",c_dequeue(&q));
    printf("dequeuing%d \n",c_dequeue(&q));
    printf("dequeuing%d \n",c_dequeue(&q));               
    
    c_enqueue(&q,4);
    c_enqueue(&q,5);
    c_enqueue(&q,6);
    if(isempty(&q)){
        printf("empty");
    }  
     if(c_isfull(&q)){
        printf("full");
    }                     
    return 0;
}       
      