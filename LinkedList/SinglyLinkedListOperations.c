#include <stdio.h>  
#include<stdlib.h>
void input();
void insertAtlast();
void display();
void insertAtMiddle();
void insertAtbegin();
void deleteitem();
void deleteAtBegin();
void deleteAtMiddle();
void deleteAtLast();

struct Node{
  int data;
  struct Node* next;
  } ;
  struct Node* head = NULL;
  struct Node* itrator = NULL;

int main() {
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
                    head = itrator;
                    break;
                case 3:
                    display();
                    head = itrator;
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
}//main close

void input()
{
    int ch;
    printf("\n1.Insert at Begining : \n2.Insert at middele : \n3.Insert at last :  \n");
    scanf ("%d",&ch);
    switch(ch)
    {
        case 1: 
            insertAtbegin();
            break;
        case 2: 
            insertAtMiddle();
            break;
        case 3: 
            insertAtlast();
            break;   
        default :
            printf("Invalid choice !");
            break;
    }
}

void insertAtbegin()
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    printf("insert data : ");
    scanf("%d",&temp-> data);
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;  
        itrator = temp;
    }
    else
    {
         temp->next = head;
         head = temp;
         itrator = temp;
    }
}


void insertAtMiddle()
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    int loc;
    printf("Enter Index :");
    scanf("%d", &loc);
    printf("insert data : ");
    scanf("%d",&temp-> data);
    //temp->next = NULL;
    
        struct Node* ghakkas;
        ghakkas = head;
        while(loc-1>0)
        {
            ghakkas = ghakkas->next;
            loc--;
        }
        temp->next = ghakkas->next;
        //ghakkas = ghakkas->next->next
        ghakkas->next = temp;

}

void insertAtlast()
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    printf("insert data : ");
    scanf("%d",&temp-> data);
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;  
        itrator = temp;
    }
    else
    {
        struct Node* ghakkas;
        ghakkas = head;
        while(ghakkas->next != NULL)
        {
            ghakkas = ghakkas->next;
        }
        ghakkas->next = temp;
    }
}

void display()
{
    while(head != NULL)
    {
       printf("%d ",head->data);
       head = head->next;
    }
    printf("\n");
}

void deleteitem()
{
    int ch;
    printf("\n1.Delete at Begining : \n2.Delete at middele : \n3.Delete at last :  \n");
    scanf ("%d",&ch);
    switch(ch)
    {
        case 1: 
            deleteAtBegin();
            break;
        case 2: 
            deleteAtMiddle();
            break;
        case 3: 
            deleteAtLast();
            break;   
        default :
            printf("Invalid choice !");
            break;
    }
}

void deleteAtLast(){
    if(head==NULL){
       printf("no element to delete \n"); 
    }
      else
      {
       while(head->next->next != NULL)
        {
            head = head->next;
        }
        free(head->next->next);
        head->next = NULL;  
      }
   
}
void deleteAtBegin(){
    if(head==NULL){
       printf("no element to delete \n"); 
    }
      else
      {
        head = head->next;
        itrator =head;
      }
   
}
void deleteAtMiddle(){
    int loc;
    printf("Enter Index :");
    scanf("%d", &loc);
    
    if(loc ==0 && head == NULL) printf("no element is found to delete !\n");
        // struct Node* ghakkas;
        // ghakkas = head;
    else
    {

        while(loc-1>0)
        {
            head = head->next;
            loc--;
        }
        head->next = head->next->next;
    }
        
}