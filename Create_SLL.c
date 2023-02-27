#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;
struct node *temp;

void create();
void display();
void exit();

void insert();
void insert_beg();
void insert_mid();
void insert_end();

void remove1();
void remove_beg();
void remove_mid();
void remove_end();

int main()
{
    int choice;

    while(choice!=5)
    {
        printf("\n 1.CREATE\n 2.INSERT\n 3.REMOVE\n 4.DISPLAY\n 5.EXIT\n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                    create();
                    break;

            case 2:
                    insert();
                    break;

            case 3:
                    remove1();
                    break;

            case 4:
                    display();
                    break;

            case 5:
                    exit(0);
                    break;

            default:    printf("\nWrong choice entered\n");
        }
    }
}

void create()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(newnode==NULL)
    {
        printf("\nCannot allocate the memory\n");
    }

    else if(head==NULL)
    {
        head=tail=newnode;
    }

    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void insert()
{
    int choice;

    printf("\n 1.Insert at beginning\n 2.Insert at Middle\n 3.Insert at End\n");
    printf("\nEnter your choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
                insert_beg();
                break;

        case 2:
                insert_mid();
                break;

        case 3:
                insert_end();
                break;

        default:    printf("\nWrong choice entered\n");
    }
}

void insert_beg()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(newnode==NULL)
    {
        printf("\nCannot allocate the memory\n");
    }

    else if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void insert_end()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(newnode==NULL)
    {
        printf("\nCannot allocate the memory\n");
    }

    else if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void insert_mid()
{
    int count=0,pos,i=0;

    printf("\nEnter the position\n");
    scanf("%d",&pos);

    temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }

     if(pos > count || pos==0)
    {
        printf("\nPlease enter the valid position\n");
    }

    else if(pos==1)
    {
        insert_beg();
    }

    else if(pos==count)
    {
        insert_end();
    }

    else
    {
        struct node *newnode,*prevnode;

        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter the data into the node\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(newnode==NULL)
        {
            printf("\nCannot allocate memory\n");
        }

        temp=head;

        while(i < pos-1)
        {
            prevnode=temp;
            temp=temp->next;
            i++;
        }

        newnode->next=temp;
         prevnode->next=newnode;

    }
}


void remove1()
{
    int choice;

    printf("\n 1.Remove at Beginning\n 2.Remove at Middle\n 3.Remove at End\n");
    printf("\nEnter your choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
                remove_beg();
                break;

        case 2:
                remove_mid();
                break;

        case 3:
                remove_end();
                break;

        default:    printf("\nWrong choice entered\n");
    }
}

void remove_beg()
{
    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}

void remove_end()
{
    struct node *prevnode;
    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        temp=head;

        while(temp!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        tail=prevnode;
        tail->next=NULL;
        free(temp);
    }
}

void remove_mid()
{
    int count,pos,i=0;

    printf("\nEnter the position\n");
    scanf("%d",&pos);

    temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }

    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else if(pos > count || pos==0)
    {
        printf("\nPlease enter the valid position\n");
    }

    else if(pos==1)
    {
        remove_beg();
    }

    else if(pos==count)
    {
        remove_end();
    }

    else
    {
        struct node *prevnode;
        temp=head;

        while(i < pos-1)
        {
            prevnode=temp;
            temp=temp->next;
            i++;
        }
        prevnode->next=temp->next;
        free(temp);
    }
}

void display()
{
    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        temp=head;

        while(temp!=NULL)
        {
                printf("%d\t",temp->data);
                temp=temp->next;
        }
    }
}
