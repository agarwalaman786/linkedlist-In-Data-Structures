#include<stdio.h>
#include<conio.h>

/*creation of new datatype node*/
struct node
{
int info;
struct node *next;	
};

struct node *start1=NULL;
struct node *start2=NULL;

// Function for sorting of the list
void sort(struct node * startx,int number_of_nodes)
{
  struct node *ptr,*nextptr;
  int temp,i;
  for(i=0;i<number_of_nodes;i++)
  {
  ptr=startx;
  nextptr=startx->next;
  while(nextptr!=NULL)
  {
  	if(ptr->info>nextptr->info)
  	{
  		temp=ptr->info;
  		ptr->info=nextptr->info;
  		nextptr->info=temp;
	}
	ptr=ptr->next;
	nextptr=nextptr->next;
  }
 }
}

/*Function Merge And sort the list*/ 
void merge_and_sort(struct node *l1,struct node *l2)
{
	
	struct node *l1ptr,*l2ptr,*l3ptr=NULL;
	struct node * sorting_pointer;
	if(l1==NULL)
	{
		display(l2);
		return;
	}
	if(l2==NULL)
	{
		display(l1);
		return;
	}
	if(l1==NULL && l2==NULL)
	{
		printf("\nList is Empty\n");
		return;
	}
	if(l1->info<=l2->info)
	{
		l3ptr=l1;
		l1=l3ptr->next;
	}
	else
	{
		l3ptr=l2;
		l2=l3ptr->next;
	}
	sorting_pointer = l3ptr;
	while(l1!=NULL && l2!=NULL)
	{
		if(l2->info<l1->info)
		{
			l3ptr->next=l2;
			l3ptr=l2;
			l2=l3ptr->next;
		}
		else
		{
			l3ptr->next=l1;
			l3ptr=l1;
			l1=l3ptr->next;
		}
	 }
	if(l1==NULL)
	   l3ptr->next=l2;
	if(l2==NULL)
	   l3ptr->next=l1;
	printf("\nSorted list after the merging operation\n");
	display(sorting_pointer);
}


/*create node function return the address of a node*/
struct node *create_node()
{
	struct node *temp;
	int data;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the information\n");
	scanf("%d",&data);
	temp->info=data;
	temp->next=NULL;
	return temp;
}


/*Function to add the node at the Beginning*/
struct node * add_at_beginning(struct node *startx)
{
	struct node *temp;
	temp=create_node();
	if(startx==NULL)
	{
		startx=temp;
	}
	else
	{
	temp->next=startx;
	startx=temp;	
	}
	return startx;
}

// Function to dislplay all the elements of the linked list;
void display(struct node *startx)
{
	struct node *ptr;
	ptr=startx;
	if(startx==NULL)
	{
	printf("List is Empty\n");	
	}
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->next;
	}
}

int main()
{
	int n1,n2;
	int i;
	
/*Entering the elements of the 1st list*/	
	printf("Enter the number of elements in the first list\n");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
	start1 = add_at_beginning(start1);
	}
	printf("Elements of the first linked list\n");
	display(start1);
	printf("\n");
  
/*Entering the elements of the 2nd list*/	
	printf("\nEnter the number of elements in the second list\n");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
	start2 = add_at_beginning(start2);
	}
	printf("\nElements of the second linked list\n");
	display(start2);
	printf("\n");

/*Sorting of the elements of the list1*/	
	sort(start1,n1);
	printf("\n");
	printf("\nList1 after the Sorting\n");
	display(start1);
	printf("\n");
	
/*Sorting of the elements of the list2*/
	sort(start2,n2);
	printf("\nList2 after the Sorting\n");
	display(start2);
	printf("\n");

/*Merging of the two sorted list*/
    merge_and_sort(start1,start2);
	getch();

return 0;
}
