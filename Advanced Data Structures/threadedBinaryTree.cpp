#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Node
{
  public:
         Node *left;
         int Left_Thread;  
         char data[20];
         int Right_Thread; 

         Node *right;
         Node()
         {
            left=right=NULL;
            Left_Thread=Right_Thread=1;
         }
         Node * Create_Node();
         void DisplayNode(Node *r);
};

Node* Node::Create_Node()
{
  Node *p;
  p = new Node;
  cout<<"\n\t Enter the data : ";
  cin>>p->data;
  p->left = NULL;
  p->right=NULL;
  p->Left_Thread=1;
  p->Right_Thread=1;
  return p;
}

void Node ::DisplayNode(Node *r)
{
  cout<<" "<<r->data;
}

class TBT:public Node
{
  public:
         Node *Root;
         TBT()
         {
            Root=NULL;
         }
         void Create();
         void Insert(Node *r,Node *p);
	 void Preorder(Node *r);	 
};

void TBT::Create()
{
  Node *p;
  p = Create_Node();
  if(Root==NULL)
  {
    Root=p;
  }
  else
  {
    Insert(Root,p);
  }
}
//INSERT 
void TBT::Insert(Node *r,Node *p)
{
  char ch;
  cout<<"\n\t Where to insert data either right/left of "<<r->data<<" : ";
  cin>>ch;
  if(ch=='l'||ch=='L')
  {
    if(r->Left_Thread==1)
    {
      p->right = r;
      p->left = r->left;
      r->left=p;
      r->Left_Thread=0;
    }
    else
    {
      Insert(r->left,p);
    }
  }
  else if(ch=='r'||ch=='R')
  {
    if(r->Right_Thread==1)
    {
      p->right = r->right;
      p->left = r;
      r->right=p;
      r->Right_Thread=0;
    }
    else
    {
      Insert(r->right,p);
    }
  } 
}

//	PREORDER
void TBT::Preorder(Node *r)
{
  int isLeft_visited=0;
  while(r!=NULL)
  {
    while(r->Left_Thread!=1 && isLeft_visited==0)
    {
      cout<<"  "<<r->data;
      r=r->left;
    }
  
    if(r->Right_Thread==1)
    {
	isLeft_visited=1;
        cout<<"  "<<r->data;
    }
    else if(r->Right_Thread==0)
    { 
       isLeft_visited=0;
    }
    r = r->right;
  }
}


int main()
{
  int choice;
  char ans;
TBT o;
  do
  {

  cout<<"\n\t MENU";
  cout<<"\n\t 1. Create ";
  cout<<"\n\t 2. Preorder ";  
  cout<<"\n\t 3. Exit";
  cout<<"\n\t Enter your choice(1,2,3) : ";
  cin>>choice;
  switch(choice)
  {
    case 1:
           o.Create();
           break;

    case 2:
           if(o.Root==NULL)
           {
             cout<<"\n\t Threaded Binary Tree is empty";
           }
           else
           {
             cout<<"\n\t Preorder Sequence : ";
             o.Preorder(o.Root);
           } 
           break;

   case 3:
           exit(0);
  }
  cout<<"\n\t Do you want to continue(yes/no) : ";
  cin>>ans;
 }while(ans=='y' ||    ans=='Y');
  return 0;
}