#include <stdio.h>

void bubblesort(int array[], int n)
{
    if (n == 1)
        return;
    int tmp,i,j;
    for (i=0; i<n-1; i++){
         for(j=i+1; j < n-1; j++){
             if(array[i] > array[j]){
                 tmp=array[i];
                 array[i]=array[j];
                 array[j]=tmp;
             }
         }
    }

}

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i <size ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int array[] = {9,10,15,14,20,5,3,14,21};
    int n = sizeof(array)/sizeof(array[0]);
    printf("Before Sorting: ");
    printArray(array,n);
    bubblesort(array, n);
    printf("After Sorting: ");
    printArray(array,n);
    return 0;
}
