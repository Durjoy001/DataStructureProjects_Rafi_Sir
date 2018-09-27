#include <stdio.h>

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i <size ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return i;
    return 0;
}

int main()
{
    int a,b,arr[]={5,10,22,15,369,52,147,854,2369,52,15,14,28,15};
    printf("Array elements: ");
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    printf("Element to search: ");
    scanf("%d", &a);
    b = search(arr, n, a);
    if(b)
       printf("\nElement Found At Index: %d\n", b);
    else
       printf("\nElement Not Found\n");
    return 0;
}
