// ------------------ Selection Sort --------------------
/*
1. Repeatedly finding target element and swapping it with the begning element of unsorted array
2. This Algorithm maintains two arrays
3. Starting from left side of the given unsorted array and finding the index of the minimum element
4. After every traversal swaping the minimun element with the begning element of unsorted array
5. This Algorith always have time complexity of O(n^2)
6. Auxillary Space O(1)
7. This algorithm is not initially stable but can be made stable
8. For making it Stable we have to store the minimum element to a temp variable, now we will shift the array elements
   to right by 1 element overiding the minimum element (till we reach the Swapping position),
   Now we will simply insert our minimum element stored in temp variable.
   This will maintain the Order of Elements.
   ----Code----
   int minVal=arr[min];
   while(min > i){
    arr[min]=arr[min-1];
    min--;
   }
   arr[i]=minVal;
*/

#include <stdio.h>
// -------------- Function for printing Array------------
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// ------------------------------------------------------
// ----------Function to perform Selection Sort----------
void selectionSort(int arr[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) min = j;
        }
        // -----Replace this code block from code given in the above notes to make it stable-----
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        // --------------------------------------------------------------------------------------
    }
}
// ------------------------------------------------------
// ------------------- Main Function --------------------
int main()
{
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array Data: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Array Before Selection Sort: ");
    printArr(arr, n);
    selectionSort(arr, n);
    printf("Array After  Selection Sort: ");
    printArr(arr, n);
    return 0;
}