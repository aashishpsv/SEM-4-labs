#include <stdio.h>
#include <stdlib.h>
int op = 0;
void topDown(int arr[], int Index)
{
    int parent = (Index - 1)/2;
    while(parent >= 0)
    {
    op++;
        if(arr[parent]<arr[Index])
        {
            int temp = arr[parent];
            arr[parent] = arr[Index];
            arr[Index] = temp;

            Index = parent;
            parent = (Index - 1)/2;
        }
        else

            return;
    }
}
void main()
{
    int h[20], n;
    printf("Enter no. of elements:\n");
    scanf("%d", &n);
    printf("Enter Elements:\n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &h[i]);
        topDown(h, i);
        for(int k = 0; k<=i; k++)
            printf("%d ", h[k]);
        printf("\n");
    }
    printf("Heapified array:\n");
    for(int i = 0; i<n; i++)
        printf("%d ", h[i]);
    printf("\n");
    printf("OP = %d\n", op);
    exit(0);
}
