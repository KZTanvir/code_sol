#include<stdio.h>
#define ARRAY_SIZE 10
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_array(int * arr, int array_size){
    for(int i=0;i<array_size;i++){
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return;
}
int main_sub(void){
    int arr[ARRAY_SIZE] = {1, 0, 5, 8, 7, 6, 4, 3, 9, 2};
    for(int i=0;i<ARRAY_SIZE;i++){
        int min_index = i;
        for(int j = i+1;j<ARRAY_SIZE;j++){
            if(arr[j] < arr[min_index]){
                //comparing current min index
                min_index = j;
            }
        //this is for swapping
        swap(&arr[min_index],&arr[i]);
        }
    }
    print_array(arr,ARRAY_SIZE);
    return 0;
}
/*
int main(void){
    main_sub();
    return 0;
}
*/