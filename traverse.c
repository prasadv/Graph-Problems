#include<stdio.h>
#include<malloc.h>
struct edge
{
   int val;
   struct edge* link;
};
struct node
{
   int info;
   struct node* next;
   struct edge* nxt;
};
struct node* start=NULL;

struct que
{
 int v;
 struct que* lk;
};
struct que* front=NULL;
struct que* rear=NULL;

struct stack
{
 int v;
 struct stack* lk;
};
struct stack* top=NULL;
	
int insert(int,int);
int traverse();
int bfs(int,int);
int dfs(int,int);
int insrtq(int);
int insrts(int);
int delts();
int delt();
int main()
{
 int n1,n2,ch,c,s,n;
 do
 { 
   printf("Menu ! \n1.Insert 2.View Graph 3.BFS 4.DFS 5.Quit\n");
   scanf("%d",&ch);
   switch(ch)
   	{
   		case 1:  printf("\n Enter the node values between which an edge is needed\n");
   			 scanf("%d",&n1);
   			 scanf("%d",&n2);
   			 insert(n1,n2);
   			 break;
   		case 2:  traverse();
   			 break;
   		case 3:  printf("\nEnter the starting node and total no of nodes\n");
   			 scanf("%d",&s);
   			 scanf("%d",&n);
   			 printf("\nBFS traversal is :");
   			 bfs(s,n);
   			 break;
   		case 4:  printf("\nEnter the starting node and total no of nodes\n");
   			 scanf("%d",&s);
   			 scanf("%d",&n);
   			 printf("\nDFS traversal is :");
   			 dfs(s,n);
   			 break;
   		case 5:  exit(0);
   		default: printf("\nWrong choice\n");
   	}
   printf("\nContinue ?\n1.Yes 2.No\n");
   scanf("%d",&c);
  }while(c!=2);
  
  return 0;
}
   
int insert(int n1,int n2)
{
  struct node* temp=malloc(sizeof(struct node));
  struct edge* tmp=malloc(sizeof(struct edge));
  struct node* ptr;
  struct edge* ptr1;
  if(start==NULL)
  	{
  	   tmp->val=n2;
  	   tmp->link=NULL;
  	   temp->info=n1;
  	   temp->next=NULL;
  	   temp->nxt=tmp;
  	   start=temp;
  	   return 0;
  	}
  ptr=start;
  while(ptr!=NULL)
  {
	   if(ptr->info==n1)
	   	{
	   	 ptr1=ptr->nxt;
			while(ptr1->link!=NULL)
			{
				 if(ptr1->val==n2)	{ printf("\nEdge already present !"); return 0; }
				 ptr1=ptr1->link;
			}
		
			if(ptr1->val==n2)		{ printf("\nEdge already present !"); return 0; }
			else
			{
				tmp->val=n2;
				tmp->link=NULL;
				ptr1->link=tmp;
				return 0;
			}
		}
	if(ptr->next!=NULL)		ptr=ptr->next;
	else				break;
   }
   
   tmp->val=n2;
   tmp->link=NULL;
   temp->info=n1;
   temp->next=NULL;
   temp->nxt=tmp;
   ptr->next=temp;
   return 0;
}
     
int traverse()
{
 struct node* ptr;
 struct edge* ptr1;
 if(start==NULL)	{ printf("\nGraph empty!\n"); return 0; }
 ptr=start;
 while(ptr!=NULL)
   { 
    	ptr1=ptr->nxt;
   	while(ptr1!=NULL)
   	  {
   	  	printf("%d->%d ; ",ptr->info,ptr1->val);
   	  	ptr1=ptr1->link;
   	  }
   	printf("\n");
   	ptr=ptr->next;
   }
 return 0;
}  

int insrtq(int s)
{
 struct que* tmp=malloc(sizeof(struct que));
 tmp->v=s;
 tmp->lk=NULL;
 if(front==NULL)	front=tmp;
 else			rear->lk=tmp;
 rear=tmp;
 return 0;
}

int delt()
{
 if(front==NULL)	{ printf("\nUnderflow\n"); return 0;}
 front=front->lk;
 return 0;
}
		
int bfs(int s,int n)
{
 int visited[15],i;
 if(s<0||s>n)		{ printf("\nInvalid node\n"); return 0; }
 for(i=1;i<=n;i++)
 	visited[i]=0;
 insrtq(s);
 visited[s]=1;
 printf("%d ",s);
 
 struct node* ptr;
 struct edge* ptr1;
 while(front!=NULL)
 { 
   ptr=start;
   while(ptr!=NULL)
    {
    	if(ptr->info==front->v)
    	 {
    	   ptr1=ptr->nxt;
    	   while(ptr1!=NULL)
    	   	{
	    	  	if(visited[ptr1->val]==0)
	    	  	{
	    	  		insrtq(ptr1->val);
	    	  		visited[ptr1->val]=1;
	   			printf("%d ",ptr1->val);
	   		}
	   		ptr1=ptr1->link;
   	  	 }
   	   break;
   	 }
   	 else
   	 ptr=ptr->next;
    }
    delt();
 }

return 0;
}  
		
int insrts(int s)
{
 struct stack* temp=malloc(sizeof(struct stack));
 temp->v=s;
 temp->lk=NULL;
 if(top==NULL)	top=temp;
 else
  { 
   temp->lk=top;
   top=temp;
  }
  return 0;
}

int delts()
{
 if(top==NULL)		{ printf("\nUnderflow\n"); return 0; }
 else
 	top=top->lk;
 return 0;
}
			
int dfs(int s,int n)
{
 int visited[15],save,i;
 if(s<0||s>n)		{ printf("\nInvalid node\n"); return 0; }
 for(i=1;i<=n;i++)
 	visited[i]=0;
 insrts(s);
 visited[s]=1;
 struct node* ptr;
 struct edge* ptr1;
	 while(top!=NULL)
	 { 
	   ptr=start;
	   save=top->v;
	   printf("%d ",top->v);
	   delts();
	      while(ptr!=NULL)
		    {
		    	if(ptr->info==save)
		    	 {
		    	   ptr1=ptr->nxt;
		    	   while(ptr1!=NULL)
		    	   	{
			    	  	if(visited[ptr1->val]==0)
			    	  	{
			    	  		insrts(ptr1->val);
			    	  		visited[ptr1->val]=1;
			   		}
			   		ptr1=ptr1->link;
		   	  	 }
		   	   break;
		   	 }
		   	 else
		   	 ptr=ptr->next;
		    }
	  }
}
		
