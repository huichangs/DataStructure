#include<stdio.h>
#include<stdlib.h>
#define ERROR 255

typedef char element;

typedef struct treenode{
	element key;
	struct treenode *left;
	struct treenode *right;

}TreeNode;

typedef struct{
	TreeNode* root;
}BST;

BST* createBST(){
	BST *bst = (BST*)malloc(sizeof(BST));
	bst->root = NULL;
	return bst;
}

int isEmpty(BST *bst){
	if (bst->root == NULL) return 1;
	return 0;
}

element getData(TreeNode* current){
	return current->key;
}

TreeNode* searchBST(TreeNode* root, element key){
	if(root == NULL) return NULL;
	
	if(key == root->key) return root;
    else if(key < root->key) return searchBST(root->left, key);
	else return searchBST(root->right, key);
}

TreeNode* searchBST2(TreeNode* root,element key){
	TreeNode *p = root;

	while(p != NULL){
	  if(key == p->key) return p;
	  else if (key < p->key) p = p->left;
	  else p = p->right;
	}

	return NULL;
	 
}

void insertBST(BST *bst, element key){
	TreeNode *newNode;
	TreeNode *p =bst->root;
	TreeNode *parent =NULL;


	 //새로운 키값을 삽입할 위치 선정
	while(p != NULL){
	  if(key ==p->key) return;
	  if(key < p->key){
	    parent = p;
	    p = p->left;
	  }else{
		parent = p;
		p = p->right;
	  }
	}
	//새로운 노드 생성
	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->key = key;
	newNode->left= newNode->right =NULL;

	//새로운 노드 추가
	if(parent == NULL) bst->root =newNode;
	else if(key < parent->key) parent->left = newNode;
	else parent->right = newNode;
}

int removeBST(BST *bst, element key){
	TreeNode *p =bst ->root;
	TreeNode *parent = NULL;
	TreeNode *child, *succ, *succ_parent, *succ_child;
	//1. 삭제할 노드 탐색
	while(p!=NULL){
	  if(key == p->key) break;
	   
	  if(key < p->key){
		  parent = p;
		  p = p->left;
	  }
	  else{
		  parent =p;
		  p = p->right;
	  }
	}
	if(p ==NULL){
		printf("삭제할 key가 존재하지 않습니다.");
		return 0;
	}
	//삭제
	if(p->left ==NULL && p->right ==NULL){//2-1. 차수가 0인 경우 삭제
	  if(parent == NULL){
		  bst->root=NULL;
		  free(p);
		  return 1;
	  }
	  if(parent->left == p) parent->left = NULL;
	  else parent->right = NULL;
	  free(p);
	  return 1;
	}
	  
	else if(p->left ==NULL){   	//2-2. 차수가 1인 경우 삭제
	  child = p->right;
	
	  if(parent==NULL){
		  bst->root=child;
		  free(p);
		  return 1;
	  }
	  if(parent->left ==p) parent->left = child;
	  else parent->right = child;
	  free(p);
	  return 1;
	}else if(p->right ==NULL){
	  child = p->left;
	  if(parent->left ==p) parent->left = child;
	  else parent->right = child;
	  free(p);
	  return 1;
	}
	else{                   
	   //자식노드가 2개인 경우 
       //a. succ 탐색 
      succ_parent = p;
	  succ = p->left;
	  while(succ->right != NULL){
		  succ_parent = succ;
		  succ =succ->right;
  	  }

      //b.  succ의 key값을 복사 
	  p->key =succ->key;
	
	  //c. succ_child를 succ_parent와 연결
	  succ_child = succ->left;
	  if(succ_parent->left == succ) succ_parent->left =succ_child;
	  else succ_parent->right = succ_child;
	
	  //d. succ를 삭제 	
	  p = succ;
	  free(p);
	  return 1;

  }
	
}

void preorder(TreeNode *root){
	if (root == NULL) return;

	printf("%d\t", root->key);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root){
	if (root == NULL) return;

	inorder(root->left);
	printf("%d\t", root->key);
	inorder(root->right);
}

void postorder(TreeNode *root){
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%d\t", root->key);
}




int main(){
	BST *bst1,*bst2;
	TreeNode *p;

	bst1 = createBST();
	bst2 = createBST();

	insertBST(bst1, 20);
	insertBST(bst1, 15);
	insertBST(bst1, 28);
	insertBST(bst1, 10);
	insertBST(bst1, 17);
	insertBST(bst1, 26);
	insertBST(bst1, 33);
	insertBST(bst1, 4);
	insertBST(bst1, 12);
	insertBST(bst1, 19);
	insertBST(bst1, 30);
	insertBST(bst1, 35);
	
	
	preorder(bst1->root);
	printf("\n");
	
	

	removeBST(bst1, 20);
	preorder(bst1->root);
	printf("\n");




	system("pause");
	return 0;
}
