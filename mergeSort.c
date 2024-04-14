#include<stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int subArray1 = mid - left + 1;
    int subArray2 = right - mid;

    int leftMerge[subArray1], rightMerge[subArray2];

    for (int i = 0; i < subArray1; i++) {
        leftMerge[i] = arr[left + i];
    }

    for (int j = 0; j < subArray2; j++) {
        rightMerge[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < subArray1 && j < subArray2) {
        if (leftMerge[i] <= rightMerge[j]) {
            arr[k] = leftMerge[i];
            i++;
        } else {
            arr[k] = rightMerge[j];
            j++;
        }
        k++;
    }

    
    while (i < subArray1) {
        arr[k] = leftMerge[i];
        i++;
        k++;
    }

    
    while (j < subArray2) {
        arr[k] = rightMerge[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        
        merge(arr, left, mid, right);
    }
} 

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Đây là source của quick sort.

/*
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(&arr[start], &arr[pivotIndex]);

    int i = start, j = end;
    while (i < pivotIndex || j > pivotIndex) {
        while (i < pivotIndex && arr[i] <= pivot) {
            i++;
        }

        while (j > pivotIndex && arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(&arr[i], &arr[j]);
        }
    }

    return pivotIndex;
}

void quick_sort(int arr[], int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quick_sort(arr, start, p - 1);
        quick_sort(arr, p + 1, end);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr); 
    return 0;
} */


// Đây là source code của insertion sort

/*
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    free(arr);

    return 0;
} */

// Đây là source code của bubble sort

/*
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;  // Moved the declaration inside the outer loop
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;  
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}*/

// đây là source code của selection sort

/*
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    free(arr);

    return 0;
}*/



// Đây là source code của heap sort.

/*
#include <stdio.h>

void swapFunction(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int max = i;
    if (left <= n && arr[left] > arr[max])
        max = left;
    if (right <= n && arr[right] > arr[max])
        max = right;
    if (max != i) {
        swapFunction(&arr[i], &arr[max]);
        heapify(arr, max, n);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, i, n);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n; i > 1; i--) {
        swapFunction(&arr[1], &arr[i]);
        heapify(arr, 1, i - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n + 1];  

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}*/
