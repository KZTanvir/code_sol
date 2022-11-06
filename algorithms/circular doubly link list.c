#include <stdio.h>
#include <stdlib.h>

typedef struct newNode{
    char value[100]; // the value inside the node
    struct newNode *next,*prev; ////front and back part for a node that stores the next and previous node address
}cNode;//used typedef cause of lazyness :p

cNode *cNodeGen(int value){
    cNode *newNode;//a pointer that saves cNode address
    newNode = (cNode*)malloc(sizeof(cNode));//allocating memory for newNode
    newNode->next = NULL;//assigning null value for next address
    newNode->prev = NULL;//same
    printf("Node[%d] data: ",value);
    scanf("%s",newNode->value);//taking input from user to newNode value
    return newNode;//returning the  new node address
}
void cNode_head(int totalNode,cNode **head){
    cNode *temp;
    for(int i=0;i<totalNode;i++){
        if(i==0){
            temp = (*head) = cNodeGen(i+1);//first node creation that will pointed by head
        }else{
            temp->next = cNodeGen(i+1);//generating and connecting of new nodes
            (temp->next)->prev = temp;
            temp = temp->next;//jumping to the next node via temp pointer
        }
    }
    temp->next = (*head);//linking the last next pointer to head node address and making it a circular linked list
    (*head)->prev = temp;//linking the head prev pointer to last node address and making it a circular linked list
}
int cNode_insertion(int nodeNum,int totalNode,cNode **head){
    if(nodeNum>totalNode+1 || nodeNum<1){
        printf("\n\t==========================================");
        printf("\n \t\tError! out of limit!"); //out of bound if the node position inserted is not logical
        printf("\n\t==========================================");
        return totalNode;
    }

    cNode *temp = (*head), *newNode = cNodeGen(nodeNum);

    if(nodeNum==1){
        newNode->next = (*head);//for insertion in the head of the list
        newNode->prev = (*head)->prev;
        ((*head)->prev)->next = newNode;
        (*head)->prev = newNode;
        (*head) = newNode;// so much work! :p
        return totalNode+1;
    }
    for(int i=2;i<=nodeNum;i++){
        if(i==nodeNum){//for insertion in the middle of the linked list
            newNode->prev = temp;
            newNode->next = temp->next;
            (temp->next)->prev = newNode;// such a hard work :p
            temp->next = newNode;
            return totalNode+1;
        }
        temp = temp->next;
        if(i==totalNode+1){
            temp->next = newNode;
            newNode->prev = temp;//insertion at the end
            newNode->next = (*head);
            return totalNode+1;
        }
    }
    return totalNode;//this was extra...
}
void printall(int totalNode,cNode *head){
    printf("\n\n    NAddr\t    Prev\tValue\t    Next\n\n");
    for(int i=0;i<totalNode;i++){
        printf("%10p->\t%10p\t%s\t%10p\n",head,head->prev,head->value,head->next);
        head = head->next;
    }
}
int main(void){
    //just some show!
    printf("\t\t==========================================\n");
    printf("\t\t|\tCircular Doubly Linked List      |\n");
    printf("\t\t==========================================\n");
    printf("\t\tName:MD.Kamruzzaman\n");
    printf("\t\tID:201400059\n");
    //
    cNode *head;int nodeNum,totalNode;
    printf("\nHow many nodes do you want to insert?\n-> ");
    scanf("%d",&totalNode);
    getchar();//consuming newline \n from the input buffer
    cNode_head(totalNode,&head);
    printall(totalNode,head);
    while(1){
        printf("\nOptions:\n 1. 1 to insert at first.\n 2. From 2-%d to insert at middle.\n 3. %d to insert at end/tail.\n",totalNode,totalNode+1);
        printf("\nIn which position do you want to insert?\n-> ");
        scanf("%d",&nodeNum);
        getchar();//int type input from user doesnt consume newline \n from the input buffer.. so used getchar to consume the extra \n remaining in the input buffer
        totalNode = cNode_insertion(nodeNum,totalNode,&head);
        printall(totalNode,head);
    }
}