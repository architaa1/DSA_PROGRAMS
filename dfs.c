#include<stdio.h>
#include<stdlib.h>

int visited[7]={0,0,0,0,0,0,0};
int a[7][7]= {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
        };

void dfs(int i){
    int j;
    printf("%d ",i);
    visited[i] = 1;
    for (j=0; j<7;j++) {
        if (a[i][j]==1 && visited[j]==0){
            visited[j]=1;
                dfs(j);
        }
    }
}


int main(){
    dfs(0);    //dfs(1,2,3,4,5,6)   
    return 0;
}