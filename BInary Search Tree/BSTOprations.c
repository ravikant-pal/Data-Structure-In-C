#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a > b) ? a : b)
struct BST {
	int data;
	struct BST* left;
	struct BST* right;
};
void insertElement(int data);
void deleteElement(int data);
void displayElement();
void inorderTriversal(struct BST* temp);
void preorderTrivarsal(struct BST* temp);
void postorderTriversal(struct BST* temp);
int height(struct BST* r);
struct BST* root;
struct BST* parent;
int main()
{
	int option;
	while(1)
	{
		printf("1.For Insert : \n2.For Delete : \n3.For Display : \n4.For Height : \n5.For Exit : \n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				{
					int data;
					printf("Enter the data : ");
					scanf("%d",&data);
					insertElement(data);
					break;

				}
			case 2:
				{
					int data;
					printf("Enter the node you wanna Delete : ");
					scanf("%d",&data);
					deleteElement(data);
					break;
				}
			case 3:
				displayElement();
				break;
			case 4:
				printf("%d",height(root));
				printf("\n");
				break;
			case 5:
				exit(0);
				break;
			default :
				printf("Invalid Choice ;)\n");
				break;
		}
	}
	return 0;
}
void insertElement(int data)
{
	struct BST* temp,*p;
	temp = (struct BST*)malloc(sizeof(struct BST));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	p = root;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct BST* curr = root;
		while(curr)
		{
			p = curr;
			if(temp->data > curr->data)
			{
				curr = curr->right;

			}
			else
			{
				curr = curr->left;
			}
		}
		if(temp->data > p->data)
		{
			p->right = temp;
		}
		else
		{
			p->left = temp;
		}	
	}
}
void deleteElement(int data)
{
	// struct BST* curr = root,*p;
	// while(curr->data != data)
	// {
	// 		p = curr;
	// 		if(temp->data > root->data)
	// 		{
	// 			curr = curr->right;

	// 		}
	// 		else
	// 		{
	// 			curr = curr->left;
	// 		}	
	// }
	
}
void displayElement()
{
	int option;
	printf("1.For Inorder triversal : \n2.For Preorder triversal : \n3.For Postorder triversal : \n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			printf("Inorder triversal : ");
			inorderTriversal(root);
			printf("\n");
			break;
		case 2:
			printf("Preorder triversal : ");
			preorderTrivarsal(root);
			printf("\n");
			break;
		case 3:
			printf("Postorder triversal : ");
			postorderTriversal(root);
			printf("\n");
			break;
		default :
			printf("Invalid Choice ;)\n");

	} 
}
void inorderTriversal(struct BST* temp)
{
	if(temp->left)
		inorderTriversal(temp->left);
	printf("%d ",temp->data);
	if(temp->right)
		inorderTriversal(temp->right);
}
void preorderTrivarsal(struct BST* temp)
{
	printf("%d ",temp->data);
	if(temp->left)
		preorderTrivarsal(temp->left);
	if(temp->right)
		preorderTrivarsal(temp->right);
}
void postorderTriversal(struct BST* temp)
{
	if(temp->left)
		postorderTriversal(temp->left);
	if(temp->right)
		postorderTriversal(temp->right);
	printf("%d ",temp->data);
}
int height(struct BST* r)
{
	if(r==NULL) return -1;
	return max(height(r->left),height(r->right))+1;

}