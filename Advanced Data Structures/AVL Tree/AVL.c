#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define KSIZE 20
#define MSIZE 20
#define FALSE 0
#define TRUE 1

typedef struct node
{
	char keyword[KSIZE];
	char meaning[MSIZE];
	int BF;
	struct node *left;
	struct node *right;
}node;

node * create(node *root,char k[KSIZE],char m[MSIZE],int *current);
void display(node *root);
void search(node *root,char *key);

node *create(node *root,char k[KSIZE],char m[MSIZE],int *current)
{
	node *temp1,*temp2;
	if(root==NULL)		//initial node
	{
		root=(node *)malloc(sizeof(node));
		strcpy(root->keyword,k);
		strcpy(root->meaning,m);
		root->left=NULL;
		root->right=NULL;
		root->BF=0;
		*current=TRUE;
		return(root);
	}
	if(strcmp(k,root->keyword)<0)
	{
		root->left=create(root->left,k,m,current);

		if(*current)
		{
			switch(root->BF)
			{
				case 1: temp1=root->left;
					if(temp1->BF==1)
					{
						printf("\n\nSingle rotation: LL rotation");
						root->left=temp1->right;
						temp1->right=root;
						root->BF=0;
						root=temp1;
					}
					else
					{
						printf("\n\nDouble rotation: LR rotation");
						temp2=temp1->right;
						temp1->right=temp2->left;
						temp2->left=temp1;
						root->left=temp2->right;
						temp2->right=root;
						if(temp2->BF==1)
							root->BF=-1;
						else
							root->BF=0;
						if(temp2->BF==-1)
							temp1->BF=1;
						else
							temp1->BF=0;
						root=temp2;
					}
					root->BF=0;
					*current=FALSE;
					break;
				case 0:
					root->BF=1;
					break;
				case -1:
					root->BF=0;
					*current=FALSE;
			}
		}
	}
	if(strcmp(k,root->keyword)>0)
	{
		root->right=create(root->right,k,m,current);

		if(*current)
		{
			switch(root->BF)
			{
				case 1:
					root->BF=0;
					*current=FALSE;
					break;
				case 0:
					root->BF=-1;
					break;
				case -1:
					temp1=root->right;
					if(temp1->BF==-1)
					{
						printf("\n\nSingle rotation:RR rotation");
						root->right=temp1->left;
						temp1->left=root;
						root->BF=0;
						root=temp1;
					}
					else
					{
						printf("\n\nDouble rotation:RL rotation");
						temp2=temp1->left;
						temp1->left=temp2->right;
						temp2->right=temp1;
						root->right=temp2->left;
						temp2->left=root;
						if(temp2->BF==-1)
							root->BF=1;
						else
							root->BF=0;
						if(temp2->BF==1)
							temp1->BF=-1;
						else
							temp1->BF=0;
						root=temp2;
					}
					root->BF=0;
					*current=FALSE;
			}
		}
	}
	return(root);
}

void display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("\n%s\t\t%s",root->keyword,root->meaning);
		display(root->right);
	}
}


void search(node *root, char *key)
{
	node *temp;
	int flag=0;
	temp=root;
	while(temp!=NULL)
	{
		if((strcmp(temp->keyword,key)==0))
		{
			printf("\n Meaning:%s",temp->meaning);
			flag=1;
			break;
		}
		if((strcmp(temp->keyword,key)>0))
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(flag==0)
	printf("\n The keyword is not in the dictionary");
}

void main()
{
	node *root=NULL;
	int current;
	char k[KSIZE],m[MSIZE];
	char key[KSIZE];
	FILE *fp=NULL;
	
	fp=fopen("input.txt","r");
	if(fp==NULL)
	{
		printf("\n Error ");
		return;
	}
	printf("\nReading the keywords from the dictionary file... ");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s",k,m);
		root=create(root,k,m,&current);
		fflush(fp);
	}
	fclose(fp);
	printf("\nReasonably Balanced Tree is created ... ");
	printf("\nThe inorder traversal of the tree is :\n ");
	display(root);
	printf("\nEnter the keyword to be searched from the dictionary: ");
	scanf("%s",key);
	search(root, key);
	printf("\n");
}