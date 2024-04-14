#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[],int n){
for(int i = 0;i<n;i++){
int min = i;
for(int j = i + 1; j < n;j++){
    if(arr[min] > arr[j]) min = j;
}
swap(&arr[i],&arr[min]);
}
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
    for(int i = 0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}