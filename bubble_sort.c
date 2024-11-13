#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size){
    for(int i=size; i>=0; i--){
        int flag = 0;
        for(int j=0; j<=i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}


int main(void){
    int arr[50];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    bubble_sort(arr, n-1);
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
}
