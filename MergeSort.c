// ------------------------ Merge Sort-----------------------------
/*
This algorithm is based on divide and conquer strategy, that is dividing the large Problems to sub-Problems
Algorithm:
         DAC(P){
             if (P is Small){
                 Solve(p)
             }
             else {
                 // divide P into P1, P2, P3, ... , Pk
                 Apply DAC(P1), DAC(P2)...
                 combibe (DAC(P1), DAC(P2), ...)
             }
         }
---------------------------------------------------------------
1. Merge sort is sorting Algorithm based on DAC
2. Suitable for large data
3. Problem is divided into multiple sub-problems, and each problem is solved individually, and all the sub-problems are combined togeather
4. Time complexity is O(nLog(n)), Ω(nLog(n))
5. This Algorithm requires Auxillary Space O(n)
6. Stable
*/

#include <stdio.h>
// ----------- Function for printing Array ------------
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// ------------------------------------------------------
void merge(int arr[], int mid, int low, int high) // Function to merge the divided parts
{
    int i = low, j = mid + 1, k = low, tempArr[high + 1];
    while (i <= mid && j <= high)
    {
        (arr[i] < arr[j]) ? (tempArr[k++] = arr[i++]) : (tempArr[k++] = arr[j++]);
    }
    while (i <= mid) {tempArr[k++] = arr[i++];}
    while (j <= high) {tempArr[k++] = arr[j++];}
    // ---copying the elemnts from tempArr to main Array---
    for (int i = low; i <= high; i++) {arr[i] = tempArr[i];}
}
// ------------------------------------------------------
void mergeSort(int arr[], int low, int high) // Function to divide the given Array to sub-problems
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }
}
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
    mergeSort(arr, 0, n);
    printf("Array After  Selection Sort: ");
    printArr(arr, n);
    return 0;
}