#include <stdio.h>

int bs(int ar[], int l, int h, int x){
    if (h >= l){
        int m = l + (h - l)/2;
        if (ar[m] == x)
            return m;
        if (ar[m] > x)
            return bs(ar, l, m-1, x);
        return bs(ar, m+1, h, x);
    }
    return 0;
}

void printArray(int arr[], int size){
    int i;
    for(i=0; i <size ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    int r,y,p,ar[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n= sizeof(ar)/sizeof(ar[0]);
    printf("Array elements: ");
    printArray(ar, n);
    printf("Element to search:");
    scanf("%d", &y);
    p=bs(ar,0,n-1,y);
    if(p)
        printf("Element Found At Index: %d\n", p);
    else
        printf("Not Found");
    return 0;
}
