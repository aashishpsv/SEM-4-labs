#include<stdio.h>


unsigned int minimum(unsigned int m,unsigned int n){

	return m>n?n:m;
}



unsigned int consecutive_int(unsigned int m, unsigned int n)
{
	unsigned int min;

	int opcount=0;
	min = minimum(m,n);
    while(min>0){

    	opcount++;
    	if(m%min == 0)
    	   {
    	   	if(n%min == 0){
                 printf("Operation count= %d\n", opcount);
                 return min;
    	   	}
    	   }
    	min--;

    }
     
printf("Operation count= %d\n", opcount);
return min;
}



int main() {
unsigned int m,n;
printf("Enter the two numbers whose GCD has to be calculated");
scanf("%d", &m);
scanf("%d", &n);
printf("GCD of two numbers using consecutive integer method is %d \n",consecutive_int(m,n)); 
return 0;
}