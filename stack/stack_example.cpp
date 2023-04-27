//4-2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct{
   int student_no;
   char name[MAX_STRING];
   char address[MAX_STRING];
} element;

typedef struct {
   element data[MAX_STACK_SIZE];
   int top;
}S;

void init_stack(S* s)
{
   s->top = -1;
}

int is_E(S* s)
{
   return(s->top == -1);
}
int is_F(S* s)
{
   return (s->top == (MAX_STACK_SIZE - 1));
}

void push(S* s, element item)
{
   if (is_F(s)) {
      fprintf(stderr, "스택 포화 에러|n");
      return;
   }
   else s->data[++(s->top)] = item;
}
element pop(S* s)
{
   if (is_E(s)) {
      fprintf(stderr, "스택 공백 에러|n");
      exit(1);
   }
   else return s->data[(s->top)--];
}
element peek(S* s)
{
   if (is_E(s)) {
      fprintf(stderr, "스택 공백 에러|n");
      exit(1);
   }
   else return s->data[s->top];
}

void printStack(S* s){
   while (!is_E(s)) {
        element printS = pop(s);
        printf("학번 : %d, 이름: %s, 주소: %s\n", printS.student_no, printS.name, printS.address);
    }
}

int main(){
   element std1 = {201866015, "김윤재", "부산 북구"};
   element std2 = {201800001, "허지웅", "부산 남구"};
   element std3 = {201800002, "김성욱", "부산 부산진구"};
   
   S s;

    init_stack(&s);

    push(&s, std1);
    push(&s, std2);
    push(&s, std3);

    printStack(&s);
   
   return 0;
}
