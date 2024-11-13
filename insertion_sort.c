#include <stdio.h>

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int insertion_sort(int arr[], int size, int n, int passes){
    int flag = 0;
    if(n < size){ 
        for(int i=n-1; i >= 0; i--){
            if(arr[n]<arr[i]){
                swap(&arr[n], &arr[i]);
                n = i;
                flag = 1;
            }
            else return insertion_sort(arr, size, n+1, passes);
        }
    }
    else{
        return 0;
    }
    
    return insertion_sort(arr, size, n+1, passes+1);
}

int main(void){
    int arr[50], size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i=0;i<size; i++) scanf("%u",&arr[i]);
    insertion_sort(arr, size, 1, 0);
    for(int i=0; i<size; i++) printf("%d\t", arr[i]);
}
