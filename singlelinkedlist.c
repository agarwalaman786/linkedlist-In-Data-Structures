#include<stdio.h>
#include<conio.h>

/*creation of new datatype node*/
struct node
{
int info;
struct node *next;	
};


struct node *start=NULL;

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


/*Function to add the node at the beginning*/
void add_at_beginning()
{
	struct node *temp;
	temp=create_node();
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
	temp->next=start;
	start=temp;	
	}
}


/*Function to add the node at the last*/
void add_at_last()
{
	struct node *ptr,*temp,*pptr;
	temp=create_node();
	ptr=start;
	if(start==NULL)
	{
		start=temp;
	}
	while(ptr!=NULL)
	{
		pptr=ptr;
		ptr=ptr->next;
	}
	pptr->next=temp;
}

// Fuction to count the number of nodes in the linked list;
int countx()
{
	struct node *ptr;
	int count=0;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}

// Fucnction to insert the data anywhere;
void insert_anywhere()
{
	struct node *temp,*ptr,*fptr;
	int position,count=1;
	printf("Enter the position\n");
	scanf("%d",&position);
	if(position<=countx())
	{
	   if(position==1)
	   {
    		add_at_beginning();
	   }
	   else if(position==countx())
	   {
	    	add_at_last();
	   }
	   else
	   {
	    	ptr=start;
	    	temp=create_node();
	    	while(ptr!=NULL)
		     {
			   count++;
			   if(position==count)
			     {
				   temp->next=ptr->next;
				   ptr->next=temp;
				   return;
			     }
			    else
			     {
				   ptr=ptr->next;
			     }
		     }
	   }
}
	    else
	    {
	    	printf("position is out of range\n");
		}
}

/*Function to display all the elements */
void display()
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
	printf("List is Empty\n");	
	}
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->next;
	}
}

//Function to delete the particular element;
void delete_the_element()
{
	struct node *ptr,*temp,*nextptr;
	int number;
	printf("Enter the element you want to delete\n");
	scanf("%d",&number);
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(number==start->info)
	{
		temp=start;
		start=start->next;
		free(temp);
		printf("Element successfully deleted\n");
		return;
	}
	ptr=start;
	nextptr=start->next;
	while(nextptr!=NULL || ptr!=NULL)
	{
		if(nextptr->info==number)
		{
			temp=nextptr;
			ptr->next=nextptr->next;
			free(temp);
			printf("Element deleted successfully\n");
			break;
		}
		else
		{
			ptr=ptr->next;
			nextptr=ptr->next;
		}
	}
}


// Function to count the nodes in the linked list;
int count()
{
	int count=0;
	struct node *ptr;
	if(start==NULL)
	{
		return count;
	}
 	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			count++;
			ptr=ptr->next;
		}
	}
	return count;
}


//Fuction to delete the element from the given position;
void delete_the_element_at_the_given_position()
{
	struct node *ptr,*temp;
	int position,i,counter=2;
	printf("Enter the position to remove the element\n");
	scanf("%d",&position);
	if(start==NULL)
	    { 
		  printf("List is empty\n");
		  return;
	    }
	else
	{
	temp = start;
	ptr = start->next;
	if(position==1)
	{
	    temp=start;
	    start=start->next;
		free(temp);
		printf("Element successfully deleted\n");
		return;
	}
	else if(position<=count())
	{
		while(counter!=position)
		{
			counter++;
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		printf("Element deleted successfully\n");
		free(ptr);
		return;
    }
    else
    {
    	printf("Position is not in range\n");
    	return;
	}
    }
}


//Fuction to serach the element in the linked list;
void Search_the_element()
{
	struct node *ptr;
	int data,counter=0;
	printf("Enter the number you want to search\n");
	scanf("%d",&data);
	if(start==NULL)
	{
		printf("List is Empty");
		return;
	}
	ptr=start;
	while(ptr!=NULL)
	{
		counter++;
		if(ptr->info==data)
		{
			printf("Element exist\n");
			break;
		}
		else
		{
			ptr=ptr->next;
	    }
	}
	if(counter==count())
	{
		printf("Element does not exist\n");
	}
}
int main()
{
	int choice;
	while(1)
	{
		system("cls");
		printf("1.Insert the element at the beginning\n2.Insert the element at the end\n3.Insert the element anywhere\n4.Delete the element\n5.Delete the node at the given position\n6.Search the element\n7.Display\n8.exit");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add_at_beginning();
				break;
			case 2:
				add_at_last();
				break;
			case 3:
				insert_anywhere();
				break;
			case 4:
				delete_the_element();
				getch();
				break;
			case 5:
				delete_the_element_at_the_given_position();
				getch();
				break;
			case 6:
				Search_the_element();
				getch();
				break;
			case 7:
				display();
				getch();
				break;
			case 8:
				exit(0);
			default:
				printf("Wrong Choice\n");
		}
	}
	getch();
	return 0;
}
