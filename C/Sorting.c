#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<(n-i-1);j++)
		{
			if(a[j]>a[j+1])
			{
			int temp =a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		}
	}
}
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
    int cur=a[i];
    int j=i-1;
    while(j>=0 && a[j]>cur)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=cur;
    }
}
void selection_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i;j<=n-1;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		// swap(a[i],a[min]);
    	int temp =a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}


int main()
{
    int choice;
    printf("1.Bubble Sort\n2.Insertion Sort\n3.Selection sort\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter the size of the array ");
        int n1;
        scanf("%d",&n1);
        int a1[10000]={0};
        for(int i=0;i<n1;i++)
        {
            scanf("%d",&a1[i]);
        }
        bubble_sort(a1,n1);
        printf("Sorted Array using Bubble sort: ");
        for(int i=0;i<n1;i++)
        {
            printf("%d ",a1[i]);
        }
        break;
    case 2:
        printf("Enter the size of the array ");
        int n2;
        scanf("%d",&n2);
        int a2[10000]={0};
        for(int i=0;i<n2;i++)
        {
            scanf("%d",&a2[i]);
        }
        insertion_sort(a2,n2);
        printf("Sorted Array using Insertion sort: ");
        for(int i=0;i<n2;i++)
        {
            printf("%d ",a2[i]);
        }
        break;
    case 3:
        printf("Enter the size of the array ");
        int n3;
        scanf("%d",&n3);
        int a3[10000]={0};
        for(int i=0;i<n3;i++)
        {
            scanf("%d",&a3[i]);
        }
        selection_sort(a3,n3);
        printf("Sorted Array using Selection sort: ");
        for(int i=0;i<n3;i++)
        {
            printf("%d ",a3[i]);
        }
        break;
    
    default:
        break;
    }
}
