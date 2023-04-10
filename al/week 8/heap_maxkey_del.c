#include<stdio.h>


void heapify(int h[],int n){
	int i,k,v,heapify,j;

	for(i=n/2;i>=1;i--){
	k=i;
	v=h[k];
	heapify=0;

	while(heapify==0 && 2*k<=n){
	   j=2*k;
	   if(j<n){
	      if(h[j]<h[j+1]){
	         j=j+1;
	      }
	   }
	   if(v>=h[j]){
	    heapify=1;
	   }
	   else{
	    h[k]=h[j];
	    k=j;
	   }
	}

	h[k]=v;
	}
	return;
}

void swap(int h[], int n){
	int temp=h[1];
	h[1]=h[n];
	h[n]=h[1];

}

int main(){
int h[20],i,n;

printf("\nEnter the number of Elements:");
scanf("%d",&n);
printf("\nEnter the Elements:");
for(i=1;i<=n;i++)
scanf("%d",&h[i]);
printf("\ndisplay the array:");
for(i=1;i<=n;i++)
{
printf("%d\t",h[i]);
}
heapify(h,n);
printf("\nThe heap created:");
for(i=1;i<=n;i++)
{
printf("%d\t",h[i]);
}

printf("the max element is %d",h[1]);

swap(h,n);

heapify(h,n-1);
printf("\nThe heap created:");
for(i=1;i<=n-1;i++)
{
printf("%d\t",h[i]);
}

return 0;
}