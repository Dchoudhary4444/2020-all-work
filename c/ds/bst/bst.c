#include<stdio.h>
#include<string.h>
struct Node
{
int num;
struct Node *left,struct Node *right;
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
return ;
}
else
{
j=start;
while(1)
{
if(t->num<j-num)
{
if(j->left==NULL)
{
j->left=t;
break;
}else
{
j=j->left;
}
}//if ends here
else
{
if(j->right=NULL)
{
j->right=t;
break;
}else
{
j=j->right;
}
}//else ends here
}//while ends here
}//else ends here
}//function ends here

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
return ;
}

if(t==start)
{
if(t->left==NULL && t->right==NULL)
{
start=NULL;
free(t);
return ;
}
if(t->left==NULL)
{
start=t->right;
free(t);
return;
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
}
f->left=e;
start=t->right;
free(t);
return ;
}//start wala if
}//function ends here
int main()
{
return 0;
}