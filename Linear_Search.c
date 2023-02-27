#include <stdio.h>


int main()
{
    int n;
    printf("\nEnter the size of an array :");
    scanf("%d",&n);
    int arr[n];

    printf("\nEnter the element in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("The elements in the array are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    int search,flag=0,i=0;
    printf("\nEnter the number you want to search :");
    scanf("%d",&search);

    for(i=0;i<n;i++)
    {
        if(search == arr[i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        printf("\nThe element %d is present in the array at position %d\n",search,i);
    }
    else
    {
        printf("\nThe element %d is not present in the array\n",search);
    }

    return 0;
}
