#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[],int n){
    int swapped = 0;
    for(int i = 0;i<n-1;i++){
        for(int j = 0; j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
            }
            if(swapped == 0) break;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[100000];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}