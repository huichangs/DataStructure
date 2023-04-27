 // 5-9
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
   int front;
   int rear;
   element data[MAX_QUEUE_SIZE];
}queuetype;

void error(const char* message) {
   fprintf(stderr, "%s\n", message);
   exit(1);
}

void init_queue(queuetype* q) {
   q->front = q->rear = 0;
}
int is_empty(queuetype* q) {
   return (q->front == q->rear);
}
int is_full(queuetype* q) {
   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void queue_print(queuetype* q) {
   printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
   if (!is_empty(q)) {
      int i = q->front;
      do {
         i = (i + 1) % (MAX_QUEUE_SIZE);
         printf("%d | ", q->data[i]);
         if (i == q->rear)
            break;
      } while (i != q->front);
   }
   printf("\n");
}

void enqueue(queuetype* q, element item) {
   if (is_full(q))
      error("큐가 포화상태입니다.");
   q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
   q->data[q->rear] = item;
}

element dequeue(queuetype* q) {
   if (is_empty(q))
      error("큐가 공백입니다.");
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->data[q->front];
}

element peek(queuetype* q) {
   if (is_empty(q))
      error("큐가 공백상태입니다.");
   return q->data[(q->front + 1) & MAX_QUEUE_SIZE];
}
int main(void) {
   int option;
   int input_num;
   
   queuetype st1;
   queuetype st2;
   
   init_queue(&st1);
   init_queue(&st2);
   
   while(1){
      printf("스택 #1 : %d개 저장, %d개 저장 가능\n", (st1.rear % MAX_QUEUE_SIZE) - st1.front, MAX_QUEUE_SIZE - (st1.rear % MAX_QUEUE_SIZE - st1.front));
      printf("스택 #2 : %d개 꺼내기 가능\n", (st2.rear % MAX_QUEUE_SIZE) - st2.front);
      printf("기능 입력(1. 입력, 2. 꺼내기,  3(else). 종료)\n");
      scanf("%d", &option);
      if(option == 1){
         printf("스택 입력 : \n");
         scanf("%d", &input_num);
         enqueue(&st1, input_num);
      }else if(option == 2){
         if(is_empty(&st2)){
            int i = st1.front;
            while(!is_empty(&st1)){
               enqueue(&st2, dequeue(&st1));
            }
            printf("스택이동 완료\n");
         }
         printf("꺼내기 : %d\n", dequeue(&st2));
      }else{
         return 0;
      }
      
   }
   
   return 0;
}
