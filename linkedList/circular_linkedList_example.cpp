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
   
   //head NULL일때 p링크를 자기 자신을 가리키도록 한다.
   if(head == NULL){
      p->link = p;
      head = p;
   }
   else{ //head의 링크가 가리키는 노드를 새로운 노드의 link로 설정한다. 
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
   printf("생성된 원형 연결 리스트 : ");
   
   if(head == NULL) return;
   
   ListNode *p = head;
   
   do{
      printf("%d ", p->data);
      p = p->link;
   }while(p != head);
}

ListNode *search(ListNode* L, element data) {
   ListNode* find = L;
   //처음부터 헤더(끝)까지 갔는데 없으면 존재하지 않는 것 
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
   printf("노드의 개수 : ");
   scanf("%d", &num_node);
   
   for(i = 0; i < num_node; i++){
      int temp;
      printf("노드 #%d 데이터 : ", i + 1);
      scanf("%d", &temp);
      head = insert_first(head, temp);
   }
   
   int data;
    printf("찾을 노드의 데이터 : ");
    scanf("%d", &data);
    
    ListNode* find_node = search(head, data);
    if (find_node == NULL) {
        printf("노드가 존재하지 않음.\n");
    } else {
        printf("find 성공. \n찾은 노드의 값 : %d\n", find_node->data);
    }
   
   return 0;
}
