#include<stdio.h>
#include<stdlib.h>


void merge(int arr[], int low, int mid, int high){
    int i, j, k=low;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int *L, *R;
    L = malloc(n1*sizeof(int));
    R = malloc(n2*sizeof(int));
    if(L==NULL || R==NULL) return;
    for(i=0; i<n1; i++) L[i] = arr[low+i];
    for(j=0; j<n2; j++) R[j] = arr[mid+j+1];

    i=0, j=0;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i<n1) arr[k++] = L[i++];

    while(j<n2) arr[k++] = R[j++];
    free(L); free(R);
}


void merge_sort(int arr[], int low, int high){
    if(low<high){
        int m = (low+high-1)/2;

        merge_sort(arr, low, m);
        merge_sort(arr, m+1, high);

        merge(arr, low, m, high);
    }
}


void main(void){
    // int arr[5] = {5, 4, 3, 2, 1};
    // int size = 5;
    int arr[50], size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i=0;i<size; i++) scanf("%u",&arr[i]);
    merge_sort(arr, 0, size-1);
    for(int i=0; i<size; i++) printf("%d\t", arr[i]);
}
