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
   
   //head NULL�϶� p��ũ�� �ڱ� �ڽ��� ����Ű���� �Ѵ�.
   if(head == NULL){
      p->link = p;
      head = p;
   }
   else{ //head�� ��ũ�� ����Ű�� ��带 ���ο� ����� link�� �����Ѵ�. 
      p->link = head->link;
      head->link = p;
   }
   
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
   
   removed = head->link;
   if(removed == head) head = NULL;
   else head->link = removed->link;
   
   free(removed);
   return head;
}

ListNode* delete_node(ListNode *head, ListNode *pre){
   ListNode *removed;
   
   removed = pre->link;
   pre->link = removed->link;
   
   if(removed == head) head = pre;
   
   free(removed);
   return head;
}

int sum(ListNode *head){
   if(head == NULL) return 0;
   
   int sum_list = 0;
   ListNode *p = head;
   
   do{
      sum_list += p->data;
      p = p->link;
   }while(p != head);
   
   return sum_list;
}

void print_list(ListNode *head){
   printf("������ ���� ���� ����Ʈ : ");
   
   if(head == NULL) return;
   
   ListNode *p = head;
   
   do{
      printf("%d ", p->data);
      p = p->link;
   }while(p != head);
}

ListNode *search(ListNode* L, element data) {
   ListNode* find = L;
   //ó������ ���(��)���� ���µ� ������ �������� �ʴ� �� 
    while (find != NULL) {
        if (find->data == data) {
            return find;
        }
        find = find->link;
    }
    return NULL;
}


int main(){
   ListNode *head = NULL;
   int num_node, i;
   printf("����� ���� : ");
   scanf("%d", &num_node);
   
   for(i = 0; i < num_node; i++){
      int temp;
      printf("��� #%d ������ : ", i + 1);
      scanf("%d", &temp);
      head = insert_first(head, temp);
   }
   
   int data;
    printf("ã�� ����� ������ : ");
    scanf("%d", &data);
    
    ListNode* find_node = search(head, data);
    if (find_node == NULL) {
        printf("��尡 �������� ����.\n");
    } else {
        printf("find ����. \nã�� ����� �� : %d\n", find_node->data);
    }
   
   return 0;
}
