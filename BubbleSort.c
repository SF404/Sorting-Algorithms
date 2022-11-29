// ---------------- Bubble Sort --------------
/*
1. Simplest Sorting Technique(algorithm)
2. It works by repeatedly swapping the Elements if they are in wrong order
3. Not suitable for large data set
4. Time complexity is O(n^2) , Ω(n^2) ---> But We can make it Ω(n) by checking if there is no swap(i.e Array is Already Sorted)
5. Auxillay Space O(1) : Auxillary Space is the Extra Space used by the Program
*/
#include <stdio.h>
#include <stdbool.h>
// -------Function For Printing Array---------
void printArr(int arr[], int n)   
{
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
// -------------------------------------------
// --------- Bubble Sort Function-------------
void bubbleSort(int arr[], int n)
{
    int temp;
    bool check;
    for (int i = 0; i < n - 1; i++)
    {
        check = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check = 1;
            }
        }
        if (check == 0)
            return;
    }
}
// ---------------------------------------------
// --------------- Main Function ---------------
int main()
{   
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n); 
    int arr[n];
    printf("Enter Array Data: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Array Before Bubble Sort: ");
    printArr(arr, n);
    bubbleSort(arr, n);
    printf("Array After  Bubble Sort: ");
    printArr(arr, n);

    return 0;
}