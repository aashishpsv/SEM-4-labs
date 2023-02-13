#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char s[30],ss[30];
	int i,j=0,flag=0;
	int op;
	printf("enter string\n");
       scanf("%s",s);
	printf("enter substring\n");
       scanf("%s",ss);
    for (i=0; i < strlen(s); i++){
        while(j < strlen(ss)){
            op++;
            if(s[i+j] == ss[j]){
                j++;
                if(j == strlen(ss)){
                    flag = 1;
                }
            }
            else
                break;
        }
        if(flag== 1)
            break;
    }


       printf("\nopcount is %d \n", op);

    if(flag==1){
    	printf("sub string found\n");
    }
    else{
    	printf("sub string not found\n");
    }


}
