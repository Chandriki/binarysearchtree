#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct bstnode
{
struct bstnode *left;
int item;
struct bstnode *right;
}bst;
void main()
{
void insert_bst(bst**,int);
void inorder(bst *root);
void preorder(bst*);
void postorder(bst*);
int ch,element;
bst *loc;
bst *root=NULL;
while(1)
{
clrscr();
printf("1.insert\n");
printf("2.inorder\n");
printf("3.preorder\n");
printf("4.postorder\n");
printf("5.exit\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter elements to insert\n");
scanf("%d\n",&element);
insert_bst(&root,element);
break;
case 2:
if(root==NULL)
{
printf("Tree is empty");
}
else
{
inorder(root);
}
break;
case 3:
if(root==NULL)
{
printf("tree is empty");
}
else
{
preorder(root);
}
break;
case 4:
if(root==NULL)
{
printf("tree is empty");
}
else
{
postorder(root);
}
break;
case 5:
exit(0);
default:
printf("invalid value");
break;
}
}

}
void insert_bst(bst**tree,int element)
{
if(*tree==NULL)
{
*tree=(bst*)malloc(sizeof(bst));
(*tree)->item=element;
(*tree)->left=(*tree)->right=NULL;
}
else if(element<(*tree)->item)
{
insert_bst(&((*tree)->left),element);
}
else
{
insert_bst(&((*tree)->right),element);
}
}
void inorder(bst*root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d\n",root->item);
inorder(root->right);
}
}
void preorder(bst *root)
{
if(root!=NULL)
{
printf("%d\n",root->item);
preorder(root->left);
preorder(root->right);
}
}
void postorder(bst*root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d",root->item);
}
}

