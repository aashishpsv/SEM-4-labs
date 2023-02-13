#include<stdio.h>
#include<stdlib.h>

void bubblesort(int *a,int n){
	int i,j,min;
	int temp;
	int opcount=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j+1]<a[j]){
				opcount++;

				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
  printf("\nopcount is %d\n",opcount);
}



int main(){
	int *a;
	int i,n;
	printf("enter array size\n");
	scanf("%d",&n);
	a = (int *) malloc(sizeof(int)*n);
	printf("enter array elements\n");
	for(i=0;i<n;i++){
       scanf("%d",&a[i]);
	}

	printf("\nbefore bubble sort:\n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}

	bubblesort(a,n);

	printf("\nafter bubble sort:\n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}