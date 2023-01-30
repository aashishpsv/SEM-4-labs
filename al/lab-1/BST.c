
#include<stdio.h>
#include<stdlib.h>

typedef struct bst* BST;

struct bst{
    int data;
    BST lchild;
    BST rchild;
};

BST createnode()
{
BST x;
x = ( BST ) malloc(sizeof(struct bst)); 
 return x; 
}

BST insert(int x,BST root){
    BST temp,cur,prev;
    temp=createnode();
    temp->data=x;
    temp->lchild=temp->rchild=NULL;
 
    if(root==NULL){
        return temp;
    }

    prev=NULL;
    cur=root;

    while(cur!=NULL){
        prev=cur;

        if(x==cur->data){
            printf("key found");
            free(temp);

            return root;
        }
        if(x<cur->data)
            cur=cur->lchild;
        else
            cur=cur->rchild;
    }

    if(x<prev->data)
        prev->lchild=temp;
    else
        prev->rchild=temp;
    
    return root;
}


void inorder(BST root)
{
if ( root == NULL ) return;
 inorder(root->lchild);  
 printf("%d ",root->data); 
 inorder(root->rchild); 
}

void postorder(BST root)
{
if ( root == NULL ) return;
 postorder(root->lchild);   
 postorder(root->rchild); 
 printf("%d ",root->data);
}

void preorder(BST root)
{
if ( root == NULL ) return;
printf("%d ",root->data);
 preorder(root->lchild);  
 preorder(root->rchild); 
}

void main(){
    BST root,cur;
    int ch,x;
    root=NULL;

    do{
      printf("\n1)insert 2)inorder 3)postorder 4)preorder 5)exit\n");
      scanf("%d",&ch);
      switch(ch){
        case 1: printf("enter data\n");
                scanf("%d",&x);
                root=insert(x,root);
                break;
        case 2: inorder(root);
                break;
        case 3: postorder(root);
                break;
        case 4: preorder(root);
                break;
      }
    }while(ch!=6);
}
