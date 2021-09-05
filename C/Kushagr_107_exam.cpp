#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    
    int i,x,pos;
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
 
    printf("Enter the element that needs to be inserted: ");
    scanf("%d",&x);

    printf("Enter the position where the element needs to be inserted: ");
    scanf("%d",&pos);
    n+=1;
    for (i = n-1; i >= pos; i--)
        arr[i] = arr[i - 1];
    
    arr[pos - 1] = x;
    
    for (i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    return 0;
}