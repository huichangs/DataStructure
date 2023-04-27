#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define QUEUE_SIZE 30000
#define ERROR_CODE 60000

//데이터 정의
typedef char element;

typedef struct{
	element queue[QUEUE_SIZE];
	int front;
	int rear;
}ArrayQueue;

ArrayQueue* createQueue(){
	ArrayQueue *q;
	q = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	q->front = -1;
	q->rear = -1;
	return q;
}

int isEmpty(ArrayQueue *q){
	if(q->front == q->rear) return 1;
	else return 0;
}

int isFull(ArrayQueue *q){
	if((q->rear+1)%QUEUE_SIZE == q->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int enQueue(ArrayQueue *q, element data){
	if(isFull(q)){
		printf("Queue isoverflow!!\n");
		return 0;
	}
	q->rear = (q->rear + 1) % QUEUE_SIZE;
	q->queue[q->rear] = data;
	return 0;
}

element deQueue(ArrayQueue *q){
	if(isEmpty(q)){
		printf("Queue is underflow!!\n");
		return ERROR_CODE;
	}

	q->front = (q->front + 1) %QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(ArrayQueue *q){
	if(isEmpty(q)){
		printf("Queue is underflow!!\n");
		return ERROR_CODE;
	}

	return q->queue[q->front +1];
}

void printQueue(ArrayQueue *q){
	int i = (q->front+1)%QUEUE_SIZE;

	if(q->front == q->rear) return;

	while(1){
		printf("%c", q->queue[i]);
		if(i == q->rear)break;

		i = (i + 1)%QUEUE_SIZE;
	}
	printf("\n");
}

int main(){
	char temp[QUEUE_SIZE];
	char find[25];
	int lengthFind, lengthTemp;
	int i,j;
	
	ArrayQueue *s;
	s = createQueue();
	
	printf("검열할 문자 입력 : ");
	scanf("%s", find);
	
	printf("텍스트 입력 : ");
	scanf("%s", temp);
	
	lengthFind = strlen(find);
	lengthTemp = strlen(temp);
	
	for(i = 0; i < lengthTemp; i++){
		enQueue(s, temp[i]);
	}
	
	printQueue(s);
	
	printf("%d\n", strncmp(find, s->queue, lengthFind));
	
	
	if(strncmp(find, s->queue, lengthFind) == 0){
		for(j = 0; j < lengthFind; j++){
			deQueue(s);
		}
	}
	
	printQueue(s);
	
	

	
	return 0;
}
