#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node 
{
	int key ;
	int degree;
	struct node * parent;
	struct node * child;
	struct node * left;
	struct node * right;
	int mark;
};
struct node * create(int data)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node ));
	temp->key=data;
	temp->degree=0;
	temp->parent=NULL;
	temp->child=NULL;
	temp->left=temp;
	temp->right=temp;
	temp->mark=0;
	return temp;
}
struct node * last(struct node * tree, struct node *original)
{
	if(tree->right!=original)
	{
		return last(tree->right,original );
	}
	else
		return tree;
}
struct node * min(struct node * tree)
{
	struct node * minimum=tree;
	struct node *temp=tree->right;
	while(temp!=tree)
	{
		if(minimum->key>temp->key)
			minimum=temp;
		temp=temp->right;
	}
	return minimum;
}
struct node * insert(struct node * tree, int data)
{
	if(tree!=NULL)
	{
	struct node * temper=last(tree,tree);
	struct node * temp=create(data);
	temper->right=temp;
	temp->left=temper;
	temp->right=tree;
	tree->left=temp;
	return min(tree);
	}
	else
	{
		tree=create(data);
		return tree;
	}
}
struct node * concatenate(struct node * one, struct node * two)
{
	if(one!=NULL&&two!=NULL)
	{
		struct node * pointer_to_be_returned;
		if(min(one)->key<min(two)->key)
			pointer_to_be_returned=min(one);
		else
			pointer_to_be_returned=min(two);
		struct node * temp;
		temp=one->right;
		struct node * tempi;
		tempi=two->left;
		one->right=two;
		two->left=one;
		temp->left=tempi;
		tempi->right=temp;
		return pointer_to_be_returned;
	}
	else if(one==NULL&&two!=NULL)
	{
		return min(two);
	}
	else if(two==NULL&&one!=NULL)
		return min(one);
}
void print_list(struct node *tree)
{
	struct node *temp=tree;
	do
	{
		printf("%d %d  %d",temp->key , temp->degree, temp->mark );
		if(temp->child!=NULL)
		{
			printf("\t( ");
			struct node *temper=temp->child;
			do
			{
				printf("%d ,",temper->key );
				temper=temper->right;
			}while(temper!=temp->child);
			printf(" )");
		}
		printf("\n");
		temp=temp->right;
	}while(temp!=tree);
}
int number(struct node * tree)
{
	int count=0;
	struct node *temp=tree;
	do
	{
		count++;
		temp=temp->right;
	}while(temp!=tree);
	return count;
}
void create_child(struct node *one , struct node * two)
{
	if(one!=NULL&&two!=NULL)
	{
		if(one->child==NULL)
		{
			one->child=two;
			one->degree=number(two);
			struct node * temp=two;
			do
			{
				temp->parent=one;
				temp=temp->right;
			}while(temp!=two);
		}
		else
		{
			struct node *temp=two;
			do
			{
				temp->parent=one;
				temp=temp->right;
			}while(temp!=two);
			one->degree=one->degree+number(two);
			one->child=concatenate(one->child,two);
		}
	}
}
void heap_link(struct node *tree, struct node * y , struct node * x)
{
	struct node *temp=y->left;
	struct node *tempi=y->right;
	y->left=y;
	y->right=y;
	temp->right=tempi;
	tempi->left=temp;
	if(x->child==NULL)
	{
		x->child=y;
		x->degree=1;
		y->parent=x;
	}
	else
	{
		y->parent=x;
		x->degree=x->degree+1;
		x->child=concatenate(x->child,y);
	}
}
struct node * create_random(struct node *tree)
{
	int i;
	tree=create(rand()%100);
	for(i=0;i<rand()%10;i++)
	{
		tree=insert(tree,rand()%100);
	}
	return tree;
}
int main()
{
	struct node *L1,*L2,*L3;
	L1=(struct node *)malloc(sizeof(struct node));
	L2=(struct node *)malloc(sizeof(struct node));
	srand(time(NULL));
	int i;
	L1=create_random(L1);
	L2=create_random(L2);
	printf("your first random list L1 is:-\n");
	print_list(L1);
	printf("\n");
	printf("your second random list L2 is:-\n");
	print_list(L2);
	L1=concatenate(L1,L2);
	printf("\n");

	print_list(L1);
	printf("\n");
	L1=NULL;L2=NULL;
	L1=create_random(L1);
	L2=create_random(L2);
	print_list(L1);
	printf("\n\n\n");
	print_list(L2);
	create_child(L1,L2);
	printf("\n");
	print_list(L1);
	printf("\n%d and size of L2 is %d",L1->degree,number(L2));
	return 0;
}