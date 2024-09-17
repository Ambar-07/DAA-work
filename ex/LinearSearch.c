#include <stdio.h>
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = linearSearch(arr, n, x);

    if (result == -1)
    {
        printf("Element %d is not present in the array\n", x);
    }
    else
    {
        printf("Element %d is present at index %d\n", x, result);
    }
}