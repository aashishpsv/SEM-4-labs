#include<stdio.h>

void add(int* i){
	*i=*i+1;
	 return;
}

int main(){
	int i=3;
	printf("%d\n",i);

	add(&i);

		printf("%d",i);
}