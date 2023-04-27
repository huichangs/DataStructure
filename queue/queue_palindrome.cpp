 // 5-11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_QUEUE_SIZE 20

typedef char element;

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
         printf("%c", q->data[i]);
         if (i == q->rear)
            break;
      } while (i != q->front);
   }
   printf("\n");
}

void enqueue(queuetype* q, element item) {
   if (is_full(q))
      error("ť�� ��ȭ�����Դϴ�.");
   q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
   q->data[q->rear] = item;
}

element dequeue(queuetype* q) {
   if (is_empty(q))
      error("ť�� �����Դϴ�.");
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->data[q->front];
}

element peek(queuetype* q) {
   if (is_empty(q))
      error("ť�� ��������Դϴ�.");
   return q->data[(q->front + 1) & MAX_QUEUE_SIZE];
}

int main(void) {
   queuetype palindrome;
   char str_tmp[MAX_QUEUE_SIZE];
   
   printf("���ڿ� �Է� : \n");
   scanf("%[^\n]s", &str_tmp);
   init_queue(&palindrome);
   
   int size = strlen(str_tmp);
   for(int i = 0; i < size; i++){
      char c = str_tmp[i];
      
      if(c >= 65 && c <= 90){ //�빮�� �ƽ�Ű �� �� 
         c += 32;
         enqueue(&palindrome, c);
      }else if(c >= 97 && c <= 122){ // �ҹ��� �ƽ�Ű �ڵ�  
         enqueue(&palindrome, c);
      }
   }
   
   queue_print(&palindrome);
   
   for(int i = 0; i < size / 2; i++){
      if(palindrome.data[palindrome.front + i + 1] != palindrome.data[palindrome.rear - i]){
         printf("ȸ���� �ƴմϴ�.");
         return 0;
      }
   }
   printf("ȸ���� �½��ϴ�.");
   
   return 0;
}
