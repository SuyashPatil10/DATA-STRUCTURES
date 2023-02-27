#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node* create();
void preorder();
void inorder();
void postorder();


struct node
{
    int data;
    struct node* right;
    struct node* left;
};

int main()
{
    struct node* root;
    root = 0;
    root = create();

    printf("\nThe preorder sequence is \n");
    preorder(root);
    printf("\nThe inorder sequence is \n");
    inorder(root);
    printf("\nThe postorder sequence is \n");
    postorder(root);
}

struct node* create()
{
    int x;
    struct node* newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter your data into the node (-1 for no node) :\t");
    scanf("%d",&x);

    if(x == -1)
    {
        return 0;
    }

    newnode->data = x;

    printf("\nEnter left child of %d",x);
    newnode->left = create();

    printf("\nEnter the right child of %d",x);
    newnode->right = create();

    return newnode;
}

void preorder(struct node* root)
{
    if(root == 0)
    {
        return;
    }

    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root)
{
    if(root == 0)
    {
        return;
    }

    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root == 0)
    {
        return;
    }

    preorder(root->left);
    preorder(root->right);
    printf("%d\t",root->data);
}
