#include<stdio.h>
int maxVal(int *arr,int size){
    int max_val = arr[0];
    for(int i = 0;i<size;i++){
        if(arr[i]>max_val){
            max_val = arr[i];
        }
    }
    return max_val;
}
int main(void){
    return 0;
}