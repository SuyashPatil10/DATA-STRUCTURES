#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;

void create();
void display();
void exit();

void insert();
void insert_beg();
void insert_mid();
void insert_end();

/*void remove1();
void remove_beg();
void remove_mid();
void remove_end();*/

int main()
{
        int choice;

    while(choice!=5)
    {
        printf("\n 1.CREATE\n 2.INSERT\n 3.DISPLAY\n 4.EXIT\n");
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
                    display();
                    break;

            case 4:
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
    newnode->prev=NULL;

    if(newnode==NULL)
    {
        printf("\nThere is no space avaliable\n");
    }

    else if(head==NULL)
    {
        head=tail=newnode;
        newnode->next=newnode;
    }

    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=tail->next;
        newnode->next=head;
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

        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void insert()
{
    int choice;

    printf("\n 1.Insert at start\n 2.Insert at middle\n 3.Insert at end\n");
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
    }
}

void insert_beg()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("\nYou have no space to store the data\n");
    }

    else
    {
        printf("\nEnter the data into the node\n");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;

        if(head==NULL)
        {
            printf("\nThis is the only 1 node you have in the list\n");
            create();
        }

        else
        {
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
    }
}

void insert_mid()
{
    int pos,i=0,count=1;

    temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
        count++;
    }

    printf("\nEnter the position to insert\n");
    scanf("%d",&pos);

    if(pos == 1)
    {
        insert_beg();
    }

    else if(pos == 0 || pos > count)
    {
        printf("\nPlease enter the correct postion\n");
    }

    else
    {
        struct node *newnode,*prevnode;

        newnode=(struct node*)malloc(sizeof(struct node));

            if(newnode==NULL)
        {
            printf("\nYou have no space to store the data\n");
        }

        else
        {
            printf("\nEnter the data into the node\n");
            scanf("%d",&newnode->data);
            newnode->prev=NULL;
            newnode->next=NULL;

            if(head==NULL)
            {
            printf("\nThis is the only 1 node you have in the list\n");
            create();
            }

        else
        {
            temp=head;

            while(i < pos-1)
            {
                prevnode=temp;
                temp=temp->next;
                i++;
            }

            newnode->next=temp;
            newnode->prev=prevnode;
            prevnode->next=newnode;
            temp->next=newnode;
        }
    }
}
}

void insert_end()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    if(newnode==NULL)
    {
        printf("\nYou have no space to store the data\n");
    }

    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
    }
}
