#include<stdio.h>

void insertion_sort(int arr[],int n){
    for(int i = 0;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }   
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i = 0;i<n;i++) scanf("%d",&arr[i]);
    insertion_sort(arr,n);
    for(int i = 0; i < n; i++) printf("%d ",arr[i]);
    return 0;
}