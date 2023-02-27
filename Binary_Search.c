#include <stdio.h>

int main()
{
    int n,temp;
    printf("\nEnter the size of an array :");
    scanf("%d",&n);
    int arr[n];

    printf("\nEnter the element in the array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++)
        {
            if(arr[j]>arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("The elements in sorting manner:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    /*int search,flag=0,i=0;
    printf("\nEnter the number you want to search :");
    scanf("%d",&search);

    for()
    {

    }*/
}
