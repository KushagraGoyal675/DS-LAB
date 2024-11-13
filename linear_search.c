#include <stdio.h>

int linear_search(int arr[], int size, int key){
    int j = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, key;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[50];
    printf("Enter the elements");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int pos = linear_search(arr, n, key);
    if(pos!=-1){
        printf("%d is found at index %d\n", key, pos);
    }
    else{
        printf("%d is not found in the array\n", key);
    }
}