#include <stdio.h>

void merge_sort(int a[],int n,int m);
void merge(int a[],int ub,int mid,int lb);

int main()
{
    int n=8,m=0;
    int a[]={8,3,6,10,34,22,4,16};


    printf("The array elements before sorting are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

    merge_sort(a,n-1,m);

    printf("\nThe array elements after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

void merge_sort(int a[],int ub,int lb)
{
    int mid;
    if(lb < ub)
    {
         mid = (lb+ub)/2;
        merge_sort(a,mid,lb);
        merge_sort(a,ub,mid+1);
        merge(a,ub,mid,lb);
    }
}

void merge(int a[],int ub,int mid,int lb)
{
    int i = lb;
    int j = mid+1;
    int k = lb;
    int b[ub];

    while(i <= mid && j <= ub)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }

        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    if(i > mid)
    {
        while(j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for(int v=lb;v<=ub;v++)
    {
        a[v] = b[v];
    }
}
