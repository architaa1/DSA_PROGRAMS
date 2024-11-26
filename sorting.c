 #include <stdio.h>  
 #include <limits.h>   
 #include <stdlib.h>     
     
                                 //BUBBLE SORT
void printarray(int *arr, int n) {
    for (int i = 0; i < n; i++)  {
        printf("%d ", arr[i]);
    }
    printf("\n");
 }

 void bubblesort(int *arr, int n){
    int temp;
    for(int i = 1; i <=n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
             }
        }
    }
}


 int main(){
    int a[] = {5,10,7,18,9,2}; 
    int n=6;
    printarray(a,n);
    bubblesort(a,n); 
    printarray(a,n);

    return 0;
 }

                                     //INSERTION SORT

//  void INSERTIONsort(int *arr, int n){
//     int key,j;
//     for(int i = 0; i <= n-1; i++){
//         key=arr[i];
//         j=i-1; 
//         while(j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }           

// int main(){
//     int a[] = {5,10,7,18,9,2};
//     int n=6;
//     printarray(a,n);
//     INSERTIONsort(a,n);
//     printarray(a,n);

//     return 0;
//  }

                                  //SELECTION SORT 

// void SELECTIONsort(int *arr, int n){
//     int indexofmin,temp;
//     printf("running selection sort...");
//     for(int i = 0; i <= n-1; i++){
//         indexofmin = i;  
//         for(int j = i+1; j<=n-1; j++){
//             if(arr[j] < arr[indexofmin]){
//                 indexofmin = j;
//             }
//         }
//         temp = arr[i];
//         arr[i] = arr[indexofmin];
//         arr[indexofmin] =temp;
        
//     }
// }           

// int main(){
//     int a[] = {5,10,7,18,9,2};
//     int n=6;
//     printarray(a,n);
//     SELECTIONsort(a,n);
//     printarray(a,n);

//     return 0;
//  }

                                  //QUICK SORT

// int partition (int* arr, int low ,int high) {
//     int pivot,i,j;
//     pivot = arr[low];
//     i = low +1 ;
//     j = high;
//     int temp;
//     do {
//       while (arr[i] <= pivot)
//           i++ ;
//       while (arr[j] > pivot)
//           j--;
//       if (i<j){
//         temp = arr[i];
//         arr[i]=arr[j];
//         arr[j]=temp;
//         }
//     }while (i < j);
//     temp  = arr[low];
//     arr[low] = arr[j];
//     arr[j] = temp;
//     return j;
// }

// void QUICKsort(int *arr, int low,int high){
//     int partitionindex;
//     if(low < high){
//         partitionindex=partition(arr,low,high);
//         QUICKsort(arr,low,partitionindex-1);
//         QUICKsort(arr,partitionindex+1,high);
//     }
// }


// int main(){
//     int a[] = {5,10,7,18,9,2};
//     int n=6;
//     printarray(a,n);
//     QUICKsort(a,0,n-1);
//     printarray(a,n);

//     return 0;
//  }

                                            //MERGE SORT

// void merge(int *arr,int mid,int low,int high){
//     int i,j,k,b[100];
//     i=low;
//     j=mid+1;
//     k=low;
//     while ((i<=mid) && (j <= high)) {
//         if (arr[i] <= arr[j]) {
//             b[k] = arr[i];
//             i++;k++;
//         }
//         else {
//             b[k]=arr[j];
//             j++;k++;
//         }   
//     }
//     while(i<=mid) {    
//         b[k]=arr[i]; 
//         i++; 
//         k++ ;
//     }  
//     while (j <= high) { 
//         b[k] = arr[j] ;  
//         j++ ;  
//         k++ ;
//     } 
//     for (int i=low; i <= high; i++) {  
//         arr[i] = b[i] ;  
//     } 
// }

// void MERGEsort(int *arr,int low,int high){
//     int mid;
//     if (low < high) { 
//         mid=(high + low)/2; 
//         MERGEsort(arr , low , mid );  
//         MERGEsort(arr , mid+1 ,high);    
//         merge(arr,mid,low,high);  
//     } 
// }

// int main(){
//     int a[] = {5,10,7,18,9,2};
//     int n=6;
//     printarray(a,n);
//     MERGEsort(a,0,n-1);
//     printarray(a,n);

//     return 0;
// }

//                                  //COUNT SORT
// int maximum(int a[],int n) {
//     int max = INT_MIN;
//     for(int i=0;i<n;i++){
//         if(a[i] > max )
//             max = a[i];
//     }  
//     return max;
// }

// void  COUNTsort(int a[], int n) 
// { 
//     int i,j;
// 	int max=maximum(a,n);
//     int* count= (int*)malloc((max+1)*sizeof(int)); 
//     for (i=0; i<max+1; i++) {
//         count[i]=0;
//     }
//     for (int i=0; i<n; i++){
//          count[a[i]]++; 
//     }
//     i=0;
//     j=0;
//     while (i<=max) {
//         if (count[i] >0){
//            a[j] = i;
//            count[i]--;
//            j++ ;
//         }
//         else{
//         i++;
//         }
//     }
// }

// int main(){
//     int a[] = {5,10,7,18,9,2};
//     int n=6;
//     printarray(a,n);
//     COUNTsort(a,n);
//     printarray(a,n);

//     return 0;
// }

