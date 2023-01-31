#include<stdio.h>
#include<stdlib.h>

void main(){
    int x,y;

    printf("enter total no of vertices of the undirected graph");
    scanf("%d",&x);
    int a[x][x];
    int i,j;
    for(i=0;i<x;i++){
        for(j=i;j<x;j++){
            if(i==j){
                a[i][i]=0;
            }
            
            else
            {
                printf("is there an edge between %d and %d? yes-1, no-0   ",(i+1),(j+1));
                scanf("%d",&y);
                a[i][j]=a[j][i]=y;

            }
        }
    }

    printf("the adjacency list is: \n");
    for(i=0;i<x;i++){
        printf("%d's adjacenct vertices are ",(i+1));
        for(j=0;j<x;j++){
            if(a[i][j]==1){
                 printf("%d \t",(j+1));
            }
        }
        printf("\n");
    }

    printf("adjacency matrix \n");
        for(i=0;i<x;i++){
            for(j=0;j<x;j++){
                printf(" %d \t",a[i][j]);

            }
          printf("\n");
        }
    

}