// --------------------------- Insertion Sort--------------------------
/*
1. This Algorithm is very similar to sorting cards (tash ka khel)
2. In this algorithm every element is inserted to its correct position
3. e.g --> (Sorting in Increasing Order)
   2 3 1 4 3 (given unsorted Array)
   2         (single element is always Sorted)
   2|3       (inserting 3) ----> 3>2 Already sorted
   2 3|1     (inserting 1) ----> 1<3 3 is right shifted by 1 element
   2|1 3     (inserting 1) ----> 1<2 2 is right shifted by 1 element
   1 2 3|4   (inserting 4) ----> 4>3 Already sorted
   1 2 3 4|3 (inserting 3) ----> 3<4 4 is right shifted by 1 element
   1 2 3|3 4 (inserting 3) ----> 3=3 Already sorted
   1 2 3 3 4 ------------------> Sorted Array
4. In this algorithm key is checked with every element till it gets its right position
5. Inplace Algorithm, Auxillary Space O(1)
6. Time Complexity = O(n^2), Ω(n)
7. Stable Algorithm
*/

#include <stdio.h>
// ---------------- Function to print Array--------------
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// ------------------------------------------------------
// ----------Function to perform Insertion Sort----------
void insertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0) // moving the elements till the exact position of the is reached
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    printf("Array Before Insertion Sort: ");
    printArr(arr, n);
    insertionSort(arr, n);
    printf("Array After  Insertion Sort: ");
    printArr(arr, n);
    
    return 0;
}