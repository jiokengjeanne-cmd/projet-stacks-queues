#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int customerNumber;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q){
    q-> front = NULL;
    q-> rear = NULL;
}

int isEmpty(Queue q){
    return (q.front == NULL);
}

void enqueue(Queue* q, int number){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode-> customerNumber = number;
    newNode-> next = NULL;
    if(q->front == NULL){
            q->front = newNode;
            q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q){
    if(q->front != NULL){
            Node* temp= q->front;
            int val = temp->customerNumber;
            q->front = q->front->next;
            if(q->front == NULL){ q->rear = NULL;}

                 free(temp);
                 return val;
    } else { return '\0'; }
}


int peek(Queue q){
    if (q.front != NULL) return q.front->customerNumber;
    else return '\0';
}
int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 101);
    printf("customer 101 arrived and got a token\n");
    enqueue(&q, 102);
    printf("customer 102 arrived and got a token\n");
    printf("customer %d is being served\n", dequeue(&q));
    enqueue(&q, 103);
    printf("customer 103 arrived and got a token\n");
    while (!isEmpty(q)){
            printf("customer %d is being served\n", dequeue(&q));
    }
    printf("Queue is empty\n");
    return 0;
}
