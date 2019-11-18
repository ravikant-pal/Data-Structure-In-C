#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
void input();
void insertAtBegin();
void insertAtMiddle();
void insertAtLast();
void deleteitem();
void display();
void leftDisplay();
void dataDisplay();
void rightDisplay();

struct Node* head =NULL;
struct Node* itrator =NULL;
int main()
{
	int ch;
        while(1)
        {
            printf("Enter choice : \n");
            printf("\n1.Insert : \n2.Delete items: \n3.Display : \n4.For Exit : \n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    input();
                    break;
                case 2:
                    deleteitem();
                    //head = itrator;
                    break;
                case 3:
                    display();
                    //head = itrator;
                    break;
                case 4:
                    exit(0);
                    break;
                default :
                    printf("Invalid choice !");
                    break;
            }
        }

	return 0;
}

void input()
{
	int ch;
    printf("\n1.Insert at Begining : \n2.Insert at middele : \n3.Insert at last :  \n");
    scanf ("%d",&ch);
    switch(ch)
    {
        case 1: 
            insertAtBegin();
            break;
        case 2: 
            insertAtMiddle();
            break;
        case 3: 
            insertAtLast();
            break;   
        default :
            printf("Invalid choice !");
            break;
    }
}

void insertAtBegin()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	int data;
	temp->right=NULL;
	temp->left=NULL;
	printf("Enter the data  :");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
	  head = temp;
	  itrator = temp;
	}
	else
	{	
     temp->right = head;
     temp->left = NULL;
     head->left = temp;
     head = temp;
     itrator = temp;
	}
}

void insertAtMiddle()
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	int data;
	int loc;
	printf("enter index :");
	scanf("%d",&loc);

	//temp->right=NULL;
	//temp->left=NULL;
	printf("Enter the data  :");
	scanf("%d",&temp->data);
	while(loc-1>0){
		head=head->right;
		--loc;
	}
	temp->right=head->right;
	temp->left=head;
	head->right->left=temp;
	head->right=temp;
}
void insertAtLast(){}

void display()
{

	int ch;
    printf("\n1.left : \n2.node : \n3.right :  \n");
    scanf ("%d",&ch);
    switch(ch)
    {
        case 1: 
            leftDisplay();
            break;
        case 2: 
            dataDisplay();
            break;
        case 3: 
            rightDisplay();
            break;   
        default :
            printf("Invalid choice !");
            break;
    }
    
}
void leftDisplay()
{
	if(head->left == NULL)
	{
		printf("No element to display\n");
		return;
	}
	else
	{
		int loc;
		printf("Enter the index from current node : ");
		scanf("%d",&loc);
		while(loc>0)
		{
			head = head->left;
			--loc;
		}

		printf("%d ",head->data);

	}
}

void dataDisplay()
{
	printf("%d ",head->data);
}
void rightDisplay()
{
	if(head->right == NULL)
	{
		printf("No element to display\n");
		return;
	}
	else
	{
		int loc;
		printf("Enter the index from current node : ");
		scanf("%d",&loc);
		while(loc>0)
		{
			head = head->right;
			--loc;
		}

		printf("%d ",head->data);

	}
}



void deleteitem(){}

