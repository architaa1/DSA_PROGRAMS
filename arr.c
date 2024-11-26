#include <stdio.h>

                              //insertion at end array (array not full)
// int addatend(int a[],int freepos,int data){
//     a[freepos]=data;
//     freepos++;
//     return freepos;
// }
// int main(){
//     int a[10];
//     int i,n,freepos;
//     printf("enter no of elements");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         printf("enter elements");
//         scanf("%d",&a[i]);
//     }
//     freepos=n;
//     freepos=addatend(a,freepos,6);
//     for(i=0;i<freepos;i++){
//         printf("%d",a[i]);
//     } 
//     return 0;
// }
                            //insertion at end array (array is full)
// int addatend(int a[],int b[],int n,int freepos,int data){
//     int i;
//     for (i=0;i<n;i++)
//          b[i]=a[i];
//     b[freepos]=data;
//     freepos++;
//     return freepos;
// }
// int main(){
//     int a[5];
//     int i,n,freepos,size;
//     printf("enter no of elements");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         //printf("enter elements %d",i);
//         scanf("%d",&a[i]);
//     }
//     size=sizeof(a)/sizeof(a[0]);
//     freepos=n;
//     if(n==size){
//         int b[size+2];
//     freepos=addatend(a,b,size,freepos,6);
//     for(i=0;i<freepos;i++){
//         printf("%d",b[i]);
//     }
//     }
//     return 0;
// }

                                  //add at beginning 
// int addatbeg(int a[],int b[],int n,int data){
//     int i;
//     for (i=0;i<n;i++)
//          b[i+1]=a[i];               // a[i+1]=a[i]; if array not full
//     b[0]=data;                      //a[0]=data;
//     n++;
//     return n;
// }
// int main(){
//     int a[10];
//     int i,n,size;
//     printf("enter no of elements");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         printf("enter elements %d",i);
//         scanf("%d",&a[i]);
//     }
//     size=sizeof(a)/sizeof(a[0]);
//     size=n;
//     if(n==size){
//         int b[size+2];
//     n=addatbeg(a,b,size,0);
//     for(i=0;i<n;i++){
//         printf("%d",b[i]);
//     }
//     }
//     return 0;
// }
                                  
                                  //insert at a position function
// void addatpos(int a[],int b[],int n,int pos,int data){
//     int i;
//     int index=pos-1;
//     for (i=0;i<=index-1;i++){
//          b[i]=a[i];
//     }
//     b[index]=data;
//     int j;
//     for(i=pos,j=index;i<=n,j<n;i++,j++){
//         b[i]=a[j];
//     }
    
//  }
// int main(){
//     int a[10];
//     int i,n,size,pos=3;
//     printf("enter no of elements");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         //printf("enter elements %d",i);
//         scanf("%d",&a[i]);
//     }
//     size=sizeof(a)/sizeof(a[0]);
//     size=n;
//         int b[size+2];
//     addatpos(a,b,size,pos,8);
//     for(i=0;i<n+1;i++){
//         printf("%d",b[i]);
//     }
    
//     return 0;
// }                                                 

//size=size-1 and then for loop for i=o to i=size-1 to print -> deletion from last
                      
                      //deletion from first
// int delete1st(int a[],int n){
//     int i;
//     if(n==0){
//        printf("empty");
//        return n;
//     }
//     for(i=0;i<n-1;i++)
//         a[i]=a[i+1];
//         return n-1;
    
// }          
// int main(){
//     int a[10];
//     int i,n;
//     printf("enter no of elements");
//     scanf("%d",&n);
//     for(i=0;i<n;i++){
//         printf("enter elements at %d->",i);
//         scanf("%d",&a[i]);
//     }
//     n=delete1st(a,n);
//     for(i=0;i<n;i++){
//         printf("%d",a[i]);
//     }
    
//     return 0;
// }             

//                           //WAP to delete a node from a position 
// 
void delpos(int a[],int n,int pos){
    int i;
    int index=pos-1;
    for (i=0;i<=index-1;i++){
         a[i]=a[i];
    }
    for(i=index;i<n-1;i++){
        a[i]=a[i+1];
    }

    
 }
int main(){
    int a[10];
    int i,n,size,pos=3;
    printf("enter no of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter elements %d",i);
        scanf("%d",&a[i]);
    }
    size=sizeof(a)/sizeof(a[0]);
    size=n;
    // int b[size-1];
    delpos(a,size,pos);
    for(i=0;i<n-1;i++){
        printf("%d",a[i]);
    }
    
    return 0;
}                                                 

//                           //WAP for array reversal
// 
int main(){
    int a[10];
    int i,n,size;
    printf("enter no of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter elements %d",i);
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        printf("%d",a[i]);
    }
    
    return 0;
}                       