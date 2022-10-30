#include<stdio.h>
#include "selection_sort.c"
int main(void){
    int arr[ARRAY_SIZE] = {1, 0, 5, 8, 7, 6, 4, 3, 9, 2};
    for(int i=0;i<ARRAY_SIZE;i++){
        int j = i;
        int key = arr[i+1];
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
    arr[j+1] = key;
    }
    print_array(arr,ARRAY_SIZE);
    return 0;
}