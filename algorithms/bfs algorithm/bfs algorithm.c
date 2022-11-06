#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
typedef struct queue{
    int size;
    int front;
    int rear;
    int *arr;
}QUEUE;
int isEmpty(QUEUE *newq){
    if(newq->rear==newq->front){
        return 1;
    }
    return 0;
}
int isFull(QUEUE *newq){
    if(newq->rear==newq->size-1){
        return 1;
    }
    return 0;
}
void enqueue(QUEUE *newq,int val){
    if(isFull(newq)){
        printf("Queue is full\n");
    }
    else{
        newq->rear++;
        newq->arr[newq->rear]=val;
    }
}
int dequeue(QUEUE *newq){
    int flag=-1;
    if(isEmpty(newq)){
        printf("Queue is empty\n");
    }
    else{
        newq->front++;
        flag=newq->arr[newq->front];
    }
    return flag;
}
void print_matrix(int *matrix,int size){
    //print the state of the matrix
    printf("\nMatrix: \n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%4d", matrix[i*size+j]);
        }
        printf("\n");
    }
}
void print_state(QUEUE *newq,int size,bool *visited,int *elements,int *bfs){
    //print the state of the visited array
    printf("\nVisited: \n|");
    for(int i=0,j=0;i<size;i++){
        if(visited[i]){
            printf(" %d ", elements[i]);
        }
        else{
            printf(" - ");
        }
    }
    printf("|\n|");
    for(int i=0;i<size;i++){
        printf(" %s ", visited[i] ? "T" : "F");
    }
    //print the state of the queue
    printf("|\n\nQueue: ");
    for(int i=newq->front+1;i<newq->rear+1;i++){
        printf("%d ", elements[newq->arr[i]]);
    }
    printf("\n");
    //print the visited array
    //bfs[newq->front] = newq->arr[newq->front+1];
    printf("\nThe BFS: ");
    for(int i=0;i<size;i++){
        if(bfs[i]!=-1){
            printf("%d ", bfs[i]);
        }
    }
    printf("\n");
    sleep(2);
}
int main(){
//queue initialization and declaration
    QUEUE q;
    q.size = 10;
    q.front = q.rear = 0;//THE FIRST ELEMENT IS AT INDEX 1
    q.arr = (int*)malloc(q.size*sizeof(int));
//queue initilization ends.int size = 7;//number of vertices
    int root = 1;//the root nodeiindex of the graph for bfs
    //the list of elements in the graph
    int elements[10] = {1,2,3,4,5,6,7,8,9,10};
    //the adjacency matrix
    int a[10][10] = {
    //   1 2 3 4 5 6 7 8 9 10 -> node positions
        {0,1,0,0,0,0,0,0,0,0},//0th element adjucent nodes
        {0,1,1,0,0,0,0,0,0,0},//1st
        {0,1,0,0,1,0,0,0,0,0},//2nd
        {0,1,0,0,0,0,0,0,0,0},//3rd
        {0,1,0,0,0,0,0,0,0,0},//4th
        {0,1,5,0,0,0,0,0,0,0},//5th
        {0,1,0,0,0,0,0,0,0,0},//6th
        {0,1,0,0,0,0,0,0,0,0},//7th
        {0,1,0,0,0,0,0,0,0,0},//8th
        {0,1,1,0,0,0,0,0,0,0} //9th
    };
    //the visited array to confirm if the node is visited or not
    bool visited[10] = {false};
    //the bfs array
    int bfs[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//
//bfs algorithm
    int dqNode;
    enqueue(&q, root);// adding the root node for first visit
    visited[root] = true;

    system("clear");
    print_matrix((int *)a,10);
    print_state(&q,10,visited,elements,bfs);

    int i = 0;
    while (!isEmpty(&q))
    {
        dqNode = dequeue(&q);
        if(dqNode!=-1){
            bfs[i] = elements[dqNode];
            i++;
        }
        system("clear");
        print_matrix((int *)a,10);
        print_state(&q,10,visited,elements,bfs);
        for (int j = 0; j < 10; j++)
        {
            
            if(a[dqNode][j] ==1 && visited[j] == false){
                //printf("%d\n", j);
                enqueue(&q, j);
                visited[j] = true;
                system("clear");
                //bfs[i] = dqNode;
                print_matrix((int *)a,10);
                print_state(&q,10,visited,elements,bfs);
            }
        }
    }
    return 0;
}
