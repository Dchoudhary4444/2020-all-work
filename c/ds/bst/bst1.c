#include<string.h>
#include<stdio.h>
struct Node
{
int num;
struct Node *left,*right;
};
struct Node *start=NULL;
void addNode(int num)
{
struct Node *t,*j;
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=NULL;
t->right=NULL;
if(start==NULL)
{
start=t;
}else
{

j=start;
while(1)
{
if(t->num<j->num)
{
if(j->left==NULL)
{
j->left=t;
break;
}
else
{
j=j->left;
}
}//if ends here
else
{
if(j->right==NULL)
{
j->right=t;
break;
}
else
{
j=j->right;
}
}//else ends here
}//while ends 
}//else ends
}//add ends here
void removeNode(int num)
{
struct Node *t,*j,*e,*f;
t=start;
while(t!=NULL)
{
if(num==t->num)
{
break;
}
j=t;
if(num<t->num)
{
t=t->left;
}
else
{
t=t->right;
}
}//while ends here
if(t==NULL)
{
printf("%d not found \n",num);
return;
}

if(t==start)
{
if(t->left==NULL && t->right==NULL)
{
free(t);
return;
}
if(t->left==NULL)
{
start=t->right;
free(t);
return ;
}
if(t->right==NULL)
{
start=t->left;
free(t);
return ;
}
e=t->left;
f=t->right;
while(f->left!=NULL)
{
f=f->left;
}//while ends here
f->left=e;
start=t->right;
free(t);
return ;
}//start if ends here

if(t->num<j->num)
{
if(t->left==NULL && t->right==NULL)
{
j->left=NULL;
free(t);
return ;
}
if(t->left==NULL)
{
j->left=t->right;
free(t);
return ;
}
if(t->right==NULL)
{
j->left=t->left;
free(t);
return ;
}
e=t->left;
f=t->right;
while(f->left!=NULL)
{
f=f->left;
}
f->left=e;
j->left=t->right;
free(t);
}
}//left wala if ends here
else
{
if(t->right==NULL && t->left==NULL){
{
j->right=NULL;
free(t);
return ;
}
if(t->left==NULL)
{
j->right=t->right;
free(t);
return ;
}
if(t->right==NULL)
{
j->right=t->left;
free(t);
return ;
}
e=t->left;
f=t->right;
while(f->left!=NULL)
{
f=f->left;
}
f->left=e;
j->right=t->right;
free(t);
}//else ends here

}//function ends here


void inOrder()
{
if(t==NULL)
{
return;
}
inOrder(t->left);
printf("%d\n",t->num);
inOrder(t->right);
}
void preOrder()
{
if(start==NULL)
{
return ;
}
printf("%d\n",t->num);
preOrder(t->left);
preOrder(t->right);
}
void postOrder()
{
if(t==NULL)
{
return ;
}
postOrder(t->left);
postOrder(t->right);
printf("%d\n",t->num);
}
int main()
{
return 0;
}
