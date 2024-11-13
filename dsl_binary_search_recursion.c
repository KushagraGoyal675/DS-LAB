#include <stdio.h>


int binary_search(int arr[], int key, int high, int low){
    int mid;
    if(low<=high){
        mid = (high + low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) return binary_search(arr, key, mid-1, low);
        else return binary_search(arr, key, high, mid+1);
    }
    return -1;
}


int main(void){
    int arr[6] = {10, 20, 30, 40, 50, 60};
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int pos = binary_search(arr, key, 5, 0);
    if(pos!=-1){
        printf("%d is found at index %d\n", key, pos);
    }
    else{
        printf("%d is not found in the array\n", key);
    }
}