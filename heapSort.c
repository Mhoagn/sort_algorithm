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
}
