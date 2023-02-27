#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    newnode->prev=NULL;

    if(newnode==NULL)
    {
        printf("\nNo space required\n");
    }

    else if(head==NULL)
    {
        head=tail=newnode;
    }

    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
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

        default:    printf("\nWring chioce entered\n");
    }
}

void insert_beg()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    if(newnode==NULL)
    {
        printf("\nTthe list is full\n");
    }

    else if(head==NULL)
    {
        head=tail=newnode;
    }

    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void insert_mid()
{
    int pos,i=0,count=0;
    struct node *newnode;
    struct node *prevnode;

    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    printf("\nEnter your position\n");
    scanf("%d",&pos);

    temp=head;

    while(i < pos-1)
    {
        prevnode=temp;
        temp=temp->next;
        i++;
    }

    if(pos==1)
    {
        insert_beg();
    }

    else if(pos==count)
    {
        insert_end();
    }

    else if(pos==0 && pos > count)
    {
        printf("\nEnter the correct position\n");
    }

    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter the data into the node\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(newnode==NULL)
        {
            printf("\nThe list is full\n");
        }

        else if(head==NULL)
        {
            head=tail=newnode;
        }

        else
        {
            newnode->prev=prevnode;
            newnode->next=temp;
            prevnode->next=newnode;
            temp->prev=newnode;
        }
    }
}

void insert_end()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    if(newnode==NULL)
    {
        printf("\nThe list is full\n");
    }

    else if(head==NULL)
    {
        head=tail=newnode;
    }

    else
    {
        newnode->prev=tail;
        tail->next=newnode;
        tail=tail->next;
    }
}

void remove1()
{
   int choice;

    printf("\n 1.Insert at start\n 2.Insert at middle\n 3.Insert at end\n");
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

        default:    printf("\nWring chioce entered\n");
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

void remove_mid()
{
    int pos,i=0,count=0;
    struct node *prevnode;

    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }

    printf("\nEnter your position\n");
    scanf("%d",&pos);

    temp=head;

    while(i < pos-1)
    {
        prevnode=temp;
        temp=temp->next;
        i++;
    }

    if(pos==1)
    {
        remove_beg();
    }

    else if(pos==count)
    {
        remove_end();
    }

    else if(pos==0 && pos > count)
    {
        printf("\nEnter the correct position\n");
    }

    else
    {
        prevnode->next=temp->next;
        temp->next->prev=prevnode;
        free(temp);
    }

}

void remove_end()
{
   if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
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
            temp=temp->next;;
        }
    }
}
