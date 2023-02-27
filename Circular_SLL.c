#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
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
        printf("\nThe memory is full\n");
    }

    else if(head==NULL)
    {
       head=tail=newnode;
       newnode->next=newnode;
    }

    else
    {
        tail->next=newnode;
        tail=tail->next;
        tail->next=head;
    }
}

void insert()
{
    int choice;

    printf("\n1.Insert at the start\n");
    printf("2.Insert at middle\n");
    printf("3.Insert at the end\n");
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

    default:   printf("\nWrong choice entered\n");
    }
}

void insert_beg()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter th data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(newnode==NULL)
    {
        printf("\nThe memory is full\n");
    }

    else
    {
       newnode->next=head;
       head=newnode;
       tail->next=head;
    }
}

void insert_mid()
{
    int pos,count=1,i=0;

    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        count++;
    }

    printf("\nEnter the position to insert\n");
    scanf("%d",&pos);

    //if(newnode==NULL)
    //{
    //    printf("\nThe memory is full\n");
    //}

    if(pos==0 || pos > count)
    {
        printf("\nPlease enter correct position\n");
    }

    else if(pos==1)
    {
        insert_beg();
    }

    else
    {
        struct node *newnode,*prevnode;
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter the data into the node\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

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

void insert_end()
{
    struct node *newnode;

    newnode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the data into the node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(newnode==NULL)
    {
        printf("\nThe memory is full\n");
    }

    else
    {
        newnode->next=head;
        tail->next=newnode;
        tail=tail->next;
    }
}

void remove1()
{
    int choice;

    printf("\n1.Remove at the start\n");
    printf("2.Remove at middle\n");
    printf("3.Remove at the end\n");
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

    default:   printf("\nWrong choice entered\n");
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
        tail->next=head;
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
        while(temp->next!=head)
        {
            prevnode=temp;
            temp=temp->next;
        }

        tail=prevnode;
        tail->next=head;
        free(temp);
    }
}

void remove_mid()
{
    int pos,count=0,i=0;
    struct node *prevnode;

    if(head==NULL)
    {
        printf("\nThe list is empty\n");
    }

    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        count++;
    }

    printf("\nEnter the position\n");
    scanf("%d",&pos);

    if(pos==0 || pos > count)
    {
        printf("\nPlease enter correct position\n");
    }

    else if(pos==1)
    {
        remove_beg();
    }

    else
    {
        while(i < pos)
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

        while(temp->next!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
