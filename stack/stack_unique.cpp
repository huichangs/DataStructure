//4-13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;

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
   for(int i = 0; i <= s->top; i++) {
        printf("%c", s->data[i]);
    }
}

int main(){
   char num_list[MAX_STACK_SIZE];
   scanf("%s", num_list);
   int size = strlen(num_list);
   
   S s;
    init_stack(&s);
    
   for(int i = 0; i < size; i++){
      if(i == 0){
         push(&s, num_list[i]);
      }
      if(peek(&s) != num_list[i]){
         push(&s, num_list[i]);
      }
   }
    
    printStack(&s);
   
   return 0;
}
