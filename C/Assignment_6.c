#include<stdio.h>

int binary_search(int a[],int n,int k)
{
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==k)
        return mid;
        else if(a[mid]>k)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        
    }
    return -1;
}

int linear_search(int a[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("enter the no. of elements in the array");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements of array");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    int k;
    printf("enter the no, that needs to be searched");
    scanf("%d",&k);
    int choice,ans=0,ans_2=0;
    printf("enter your choice of searching");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            ans=binary_search(a,n,k);
            if(ans)
            printf("no. is present at :%d",ans);
            else
            {
                printf("%d",ans);
            }
            break;
        case 2:
            ans_2=linear_search(a,n,k);
            if(ans_2)
            printf("no. is present at : %d",ans_2);
            else
            {
                printf("%d",ans_2);
            }
            break;
        default:
            break;
    }
}