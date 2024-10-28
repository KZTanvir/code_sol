#include<stdio.h>
#include<stdbool.h>
// Number of processes
#define P 5
// Number of resources
#define R 3
// need matrix
int need[P][R];
// allocated matrix
int allocated[P][R]={
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};
// maximum matrix
int maximum[P][R]={
    {7,5,3},
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};
// available matrix
int available[R]={3,3,2};
int availableSequence[P][R];
// safe sequence
int safePass[P];
// visited array
bool visited[P];
//assigning all null value to specified values
void valueInit(){
    for(int i=0;i<P;i++){
        visited[i]=false;
    }
}
// function to check if all processes are finished
//todo: add count in the while loop to loop-out from the deadlock
bool notVisited(){
    for(int i=0;i<P;i++){
        if(visited[i]==false){
            return true;
        }
    }
    return false;
}
// function to check if the process can be allocated
bool CheckP(int pN){
    for(int i=0;i<R;i++){
        if(need[pN][i]>available[i]){
            return false;
        }
    }
    return true;
}

/*
// function to find the safe sequence
void FindSafeSequence(){
    int count=0;
    while(!IsVisited(visited)){
        for(int i=0;i<P;i++){
            if(!visited[i] && IsSafe(i,visited)){
                for(int j=0;j<R;j++){
                    available[j]+=allocation[i][j];
                }
                visited[i]=true;
                safeSequence[count++]=i;
            }
        }
    }
}

// main function
*/
void printState(){
    printf("\n              ============================================\n");
    printf("              ||        BANKERS ALGORITHM (improved)    ||\n");
    printf("              ============================================\n");
    printf("Currently Available Resources: \n");
    for(int i=0;i<P;i++){
        printf("%d ",available[i]);
    }
    printf("\n==========================================================================\n");
    printf("ProcessNo\tAllocated\tMaximum\t\tNeedMatrix\tAvailable\n");
    printf("==========================================================================\n");
    for(int i=0;i<P;i++){
        //process no.
        printf("P[%02d] ",i);
        printf("\t\t");
        //
        for(int j=0;j<R;j++){
            printf("%02d ",allocated[i][j]);
        } printf("\t");
        for(int j=0;j<R;j++){
            printf("%02d ",maximum[i][j]);
        } printf("\t");
        for(int j=0;j<R;j++){
            printf("%02d ",need[i][j]);
        } printf("\t");
        for(int j=0;j<R;j++){
            printf("%02d ",availableSequence[i][j]);
        }
        printf("\n");        
    }
    printf("\nCurrent Process Safe Sequence: \n");
    for(int i=0;i<P && !notVisited();i++){
        printf("P[%d] ", safePass[i]);
    }
    printf("\n");
};
int main(){
    printState();
    valueInit();//gives all visited process to false
    // calculate need matrix
    for(int i=0;i<P;i++){
        for(int j=0;j<R;j++){
            need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }
    //calculate safeseq and allocation sequence
    int count=0;
    while(notVisited()){
        for(int i=0;i<P;i++){
            if(!visited[i] && CheckP(i)){//same
                for(int j=0;j<R;j++){
                    available[j]=available[j]+allocated[i][j];
                    availableSequence[i][j]=available[j];
                }
                visited[i]=true;
                safePass[count++]=i;
            }
        }
        
    }

    printState();


    return 0;
}
