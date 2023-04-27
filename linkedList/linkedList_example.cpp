#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode{
   element data;
   struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode *head, int value){
   ListNode *p = (ListNode *)malloc(sizeof(ListNode));
   p->data = value;
   p->link = head;
   head = p;
   return head;
}

ListNode* insert_node(ListNode *head, ListNode *pre, element value){
   ListNode *p = (ListNode *)malloc(sizeof(ListNode));
   p->data = value;
   p->link = pre->link;
   pre->link = p;
   return head;
}

ListNode* delete_first(ListNode *head){
   ListNode *removed;
   if(head == NULL) return NULL;
   removed = head;
   head = removed->link;
   free(removed);
   return head;
}

ListNode* delete_node(ListNode *head, ListNode *pre){
   ListNode *removed;
   removed = pre->link;
   pre->link = removed->link;
   free(removed);
   return head;
}

void print_reverse(ListNode *head){
    if(head == NULL) return;
    print_reverse(head->link);
    printf("%d ", head->data);
}

void print_list(ListNode *head){
    printf("생성된 연결 리스트 : ");
    print_reverse(head);
}


int main(){
   ListNode *head = NULL;
   int num_node, i;
   printf("노드의 개수 : ");
   scanf("%d", &num_node);
   
   for(i = 0; i < num_node; i++){
      int temp;
      printf("노드 #%d 데이터 : ", i + 1);
      scanf("%d", &temp);
      head = insert_first(head, temp);
   }
   
   print_list(head);
   
   return 0;
}
