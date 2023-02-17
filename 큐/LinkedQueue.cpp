#include <stdio.h>
#include <stdlib.h>
#define ERROR_CODE 60000

//LinkedQueue데이터 정의
typedef int element;

typedef struct node{
	element data;
	struct node* link;
}Node;

typedef struct{
	Node* front, *rear;
}LinkedQueue;

//LinkedQueue연산 정의

LinkedQueue* createQueue(){
	LinkedQueue *q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	q->front = NULL;
	q->rear = NULL;

	return q;
}

int isEmpty(LinkedQueue *q){
	if(q->front == NULL) return 1;
	else return 0;
}

int enQueue(LinkedQueue *q, element x){
	Node *newNode = (Node*)malloc(sizeof(Node));

	if(newNode == NULL){
		printf("Memory allocation error!!\n");
		return 0;
	}

	newNode->data = x;
	newNode->link = NULL;

	if(isEmpty(q)){
		q->front = newNode;
		q->rear = newNode;
	}
	else{
		q->rear->link = newNode;
		q->rear = newNode;
	}
}

element deQueue(LinkedQueue *q){
	Node *temp;

	if(isEmpty(q)){
		printf("Queue is empty!\n");
		return ERROR_CODE;
	}


	temp = q->front;
	q->data = temp->data;

	if(q->front == q->rear){
		q->front = q->rear = NULL;
	}else{
		q->front = q->front->link;
	}

	q->front = q->front->link;

	free(temp);
	return data;
}

element peek(LinkedQueue *q){
	if(isEmpty(q)){
		printf("Queue isEmpty\n");
		return ERROR_CODE;
	}
	return q->front->data;
}

void printQueue(LinkedQueue *q){
	Node *temp = q->front;

	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->link;
	}
}

int main(){
	LinkedQueue *q1;

	q1 = createQueue();

	enQueue(q1, 10);
	enQueue(q1, 20);
	enQueue(q1, 30);

	system("pause");
	return 0;
}
