#include<stdio.h>
#include "selection_sort.c"

int partition_gen(int* arr, int start, int end){
    int pivot = arr[end];
    int partitionIndex = start;
    for(int i = start; i<end; i++){
        if(arr[i]<= pivot){
            swap(&arr[i],&arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&arr[partitionIndex],&arr[end]);
    return partitionIndex;
}
void quicksort(int* arr, int start, int end){
    if(start<end){
        int partitionIndex = partition_gen(arr, start, end);
        quicksort(arr,start,partitionIndex-1);
        quicksort(arr,partitionIndex+1,end);
    }
}
int main(){
    int arr[ARRAY_SIZE] = {9,2,3,4,6,1,5,8,7,0};
    quicksort(arr,0,ARRAY_SIZE-1);
    print_array(arr,ARRAY_SIZE);
    return 0;
}