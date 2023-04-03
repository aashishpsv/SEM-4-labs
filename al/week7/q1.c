#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int info;
  struct node *left,*right;
}NODE;

NODE *root = NULL;

NODE* create(NODE *bnode,int x)
{
   NODE *getnode;
   if(bnode==NULL)
    {
       bnode=(NODE*) malloc(sizeof(NODE));
       bnode->info=x;
       bnode->left=bnode->right=NULL;
    }
   else if(x>bnode->info)
       bnode->right=create(bnode->right,x);
   else if(x<bnode->info)
       bnode->left=create(bnode->left,x);
   else
   {
      printf("Duplicate node\n");
      exit(0);
    }
       return(bnode);
}

int lheight(NODE *node){
	if(node!=NULL) return(lheight(node->left)+1);
	return 0;
}

int rheight(NODE *node){
	if(node!=NULL)return(rheight(node->right)+1);
	return 0;
}



void balancefactor(NODE *node){
	 if(node != NULL){
	    printf("balance factor of %d is %d \n",node->info,(lheight(node)-rheight(node)));
	    balancefactor(node->left);
	    balancefactor(node->right);
}
}


void main()
{
   int n,x,ch,i;
  // NODE *root;
  // root=NULL;
   while(1)
   { 
      printf(" enter 1. Insert 2. balancefactor 3. Exit\n");
      scanf("%d",&ch);
      switch(ch)
       {
         case 1: printf("Enter node (do not enter duplicate nodes):\n");
                 scanf("%d",&x);
                 root=create(root,x);
                 break;
         case 2: balancefactor(root);
                 break;
         case 3: exit(0);
}
}
}