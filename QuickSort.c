// ----------------------- Quick Sort ------------------------
/*
1. Quick Sort is based on Divide and Conquer Algorithm
2. It picks an element as pivot and partitions the qiven array around it
3. e.g -------------------------------------------------------------------------------------->
   Let Given array = 4 2 8 2 9
                     p i     j       -\ move i till arr[i]<=arr[p] & j till arr[j]>arr[p]
                     4 2 8 2 9
                     p   i j         -\ swap arr[i] & arr[j]
                     4 2 2 8 9
                     p   i j         -\ move i till arr[i]<=arr[p] & j till arr[j]>arr[p]
                     4 2 2 8 9
                     p   j i         -\ swap arr[p] & arr[j]
                     2 2 4 8 9
                     p   j i
                     return j;       -\ Element at index j is at its right position,
                                        now the array is sorted for left and right sub-array in the same manner
    ------------------------------------------------------------------------------------------
4. Time Complexity --->
        Best case: O(nLog(n))
        Worst case: O(n^2)    occurs when the partition always picks the smallest or greatest element as pivot i.e Array is already Sorted
5. Unstable and Not-Inplace (O(nLog(n)))

*/
#include <stdio.h>
// --------------- Function for Printing Array ---------------
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}
// -----------------------------------------------------------
// --------------- Function to perform partition -------------
int partition(int arr[], int low, int high)
{
    int pivot = arr[low], i = low + 1, j = high, temp;
    do
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot)  j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
//-------------------------------------------------------------
// ------------------- Quick Sort Function --------------------
void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int n;
    printf("Enter the Size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements of Array: ");
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    printf("Array Before Quick Sort: ");
    printArr(arr, n);
    quickSort(arr, 0, n);
    printf("Array After  Quick Sort: ");
    printArr(arr, n);
    return 0;
}