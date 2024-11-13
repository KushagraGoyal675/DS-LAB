#include <stdio.h>

int linear_search_multiple_occurence(int arr[], int size, int key, int occurence[]){
    int j = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == key){
            occurence[j] = i;
            j++;
        }
    }
    if(j==0) return -1;
    return j;
}

int main(void){
    int arr[50], n, key, indices[50];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int occurence = linear_search_multiple_occurence(arr, n, key, indices);
    if(occurence==-1){
        printf("%d is not found in the array\n", key);
    }
    else{
        printf("%d is found %d times at index: \n", occurence, key);
        for(int i=0; i<occurence; i++){
            printf("%d ", indices[i]);
        }
        printf("\n");
    }
}