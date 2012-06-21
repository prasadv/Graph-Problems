				/* Dijkstra's algorithm */
#include<stdio.h>
#include<stdlib.h>
struct edge
{
   int val;
   int wt;
   struct edge *link;
};
struct node
{
   int info;
   int dist;
   int pred;
   int status;
   struct node *next;
   struct edge *nxt;
};
struct stack
{
 int v;
 struct stack *t;
};

struct node *start=NULL;	
int insert(int,int,int);
int traverse();
int dij(int,int);
int initialise(int);
int main()
{
 int n1,n2,ch,c,w;
 int s,d;
 do
 { 
   printf("Menu ! \n1.Insert 2.View Graph 3.Dijkstra 4.Quit\n");
   scanf("%d",&ch);
   switch(ch)
   	{
   		case 1:  printf("\n Enter the node values between which an edge is needed and weight\n");
   			 scanf("%d",&n1);
   			 scanf("%d",&n2);
   			 scanf("%d",&w);
   			 insert(n1,n2,w);
   			 break;
   		case 2:  traverse();
   			 break;
   		case 3:  printf("\nEnter the source and destination nodes\n");
   			 scanf("%d",&s);
   			 scanf("%d",&d);
   			 dij(s,d);
   			 break;
   		case 4:  exit(0);
   		default: printf("\nWrong choice\n");
   	}
   printf("\nContinue ?\n1.Yes 2.No\n");
   scanf("%d",&c);
  }while(c!=2);
  
  return 0;
}
   
int insert(int n1,int n2,int w)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  struct node *t=(struct node*)malloc(sizeof(struct node));
  struct edge *tmp=(struct edge*)malloc(sizeof(struct edge));
  if(start==NULL)
  	{
  	   tmp->val=n2;
  	   tmp->wt=w;
  	   tmp->link=NULL;
  	   temp->info=n1;
  	   temp->next=NULL;
  	   temp->nxt=tmp;
  	   start=temp;
  	   t->info=n2;
  	   t->next=NULL;
  	   start->next=t;
  	   return 0;
  	}
  struct node *ptr,*ptr2,*ptr3;
  struct edge* ptr1;
  ptr=start;
  ptr2=start;
  ptr3=start;
  while(ptr!=NULL)
  {
	   if(ptr->info==n1)
	   	{
	   	if(ptr->nxt==NULL)		
	   		      {
		   		 tmp->val=n2;
		   		 tmp->wt=w;
		   		 tmp->link=NULL;
		   		 ptr->nxt=tmp;
		   		 while(ptr2!=NULL)
		   		      {
			   		  if(ptr2->info==n2)	return 0;
			   		  ptr2=ptr2->next;
		   		       }
		   		 while(ptr3->next!=NULL)
		   		 	ptr3=ptr3->next;
		   		 temp->info=n2;
		   		 temp->next=NULL;
		   		 ptr3->next=temp;
		   		 return 0;
	   		       }
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
				tmp->wt=w;
				tmp->link=NULL;
				ptr1->link=tmp;
				while(ptr2!=NULL)	
					{
					  if(ptr2->info==n2)	return 0;
					  ptr2=ptr2->next;
					 }
				
				while(ptr3->next!=NULL)
					ptr3=ptr3->next;
				temp->info=n2;
				temp->next=NULL;
				ptr3->next=temp;
				return 0;
				 
			    }
	     }
	if(ptr->next!=NULL)		ptr=ptr->next;
	else				break;
   }
   
   tmp->val=n2;
   tmp->wt=w;
   tmp->link=NULL;
   temp->info=n1;
   temp->next=NULL;
   temp->nxt=tmp;
   ptr->next=temp;
   while(ptr2!=NULL)
      {
        if(ptr2->info==n2)	return 0;
       	ptr2=ptr2->next;
      }
   while(ptr3->next!=NULL)	
	ptr3=ptr3->next;
   t->info=n2;
   t->next=NULL;
   ptr3->next=t;
	return 0;
}
     
int traverse()
{
 struct node *ptr;
 struct edge *ptr1;
 if(start==NULL)	{ printf("\nGraph empty!\n"); return 0; }
 ptr=start;
 while(ptr!=NULL)
   { 
    	ptr1=ptr->nxt;
    	printf("%d-->",ptr->info);
   	while(ptr1!=NULL)
   	  {
   	  	printf("[%d]%d ; ",ptr1->wt,ptr1->val);
   	  	ptr1=ptr1->link;
   	  }
   	printf("\n");
   	ptr=ptr->next;
   }
 return 0;
}  

int initialise(int s)
{ 
 struct node *p;
 p=start;
 while(p!=NULL)
 {
  if(p->info==s)
  	{
  	 p->dist=0;
  	 p->pred=0;
  	 p->status=1;
  	 p=p->next;
  	 }
  else
  	{
	  p->dist=9999;
	  p->pred=0;
	  p->status=0;
	  p=p->next;
  	}
 }
 return 0;
}
  	 
int dij(int s,int d)
{ 
 if(s==d)	{ printf("\nNo minimum path.Source & destination same \n"); return 0; }
 initialise(s);
 struct node *ptr,*ptr2;
 struct edge *ptr1;
 int curr,min;
 curr=s;
     while(curr!=d)
       {
         min=9999;
 	 ptr=start;
 	 while(curr!=ptr->info)
 	 	ptr=ptr->next;
 	  
	  ptr1=ptr->nxt;
	  while(ptr1!=NULL)
	  	{   
	  	    ptr2=start;
	  	    while(ptr2->info!=ptr1->val)
	  	 	  	ptr2=ptr2->next;
	  	 	if((ptr2->status==0)&&(ptr2->dist>(ptr->dist+ptr1->wt)))
	  	 		{
	  	 		  ptr2->dist=ptr->dist+ptr1->wt;
	  	 		  ptr2->pred=ptr->info;
	  	 		 }
	  	    ptr1=ptr1->link;
	  	}
	  ptr2=start;
	 while(ptr2!=NULL)
	  {
	    if(ptr2->status==0&&ptr2->dist<min)
	         min=ptr2->dist;
            ptr2=ptr2->next;
	  }
	  ptr2=start;
	  while(ptr2->dist!=min)	ptr2=ptr2->next;
	  
	  ptr2->status=1;
	  curr=ptr2->info;
       }
printf("\nThe shortest path is :");
struct stack *tmp,*ptr3;
struct stack *top=NULL;
   while(d!=s)
	{
	  ptr=start;
	  while(ptr->info!=d)	ptr=ptr->next;
	  tmp=malloc(sizeof(struct stack));
	  tmp->v=d;
	  tmp->t=top;
	  top=tmp;
	  d=ptr->pred;
	}
printf("%d->",s);
ptr3=top;
  while(ptr3!=NULL)
	{
	 printf("%d->",ptr3->v);
	 ptr3=ptr3->t;
	}
printf("\nMinimum path length is %d",min);
return 0;
}
    				
