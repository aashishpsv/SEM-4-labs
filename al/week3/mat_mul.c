#include<stdio.h>

int main(){
	int m,n,p,q;
    int a [4][4], b[4][4],c[4][4];
    int i,j;
    printf("enter m,n of matrix a\n");
    scanf("%d %d",&m,&n);

    printf("enter p,q of matrix b\n");
     scanf("%d %d",&p,&q);
    
    if(n!=p){
    printf("matrix cant be multiplied");

    }

    else{
       printf("enter the elements of matrtix a\n");
       for(i=0;i<m;i++){
          for(j=0;j<n;j++){
          scanf("%d",&a[i][j]);
          }
       }

       printf("enter the elements of matrtix b\n");
       for(i=0;i<p;i++){
          for(j=0;j<q;j++){
          scanf("%d",&b[i][j]);
          }
       }

        printf("matrix a is\n");
       for(i=0;i<m;i++){
          for(j=0;j<n;j++){
          printf("%d\t",a[i][j]);
          }
          printf("\n");
       }

       printf("matrix b is\n");
       for(i=0;i<p;i++){
          for(j=0;j<q;j++){
          printf("%d\t",b[i][j]);
          }
          printf("\n");
       }

       for(i=0;i<m;i++){
          for(j=0;j<q;j++){
            c[i][j]=a[i][j]*b[i][j];
          }
       }

       printf("multiplied matrix c is\n");
       for(i=0;i<m;i++){
          for(j=0;j<q;j++){
           printf("%d\t",c[i][j]) ; 
          }
          printf("\n");
       }


       }

}