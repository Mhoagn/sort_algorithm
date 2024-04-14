#include <stdio.h>

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

void quickSort(int arr[], int start, int end) {
if (start < end) {
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);


    int cost = 0;
    int hp[100];
    int max = 0;
    int p;
    for(int i = 0;i<n;i++){
        hp[i] = arr[i] * (n-i);
        if(max < hp[i]){
            max = hp[i];
            cost = arr[i];
        }
    }
    printf("%d %d",max ,cost); 
    return 0;

    }
   

