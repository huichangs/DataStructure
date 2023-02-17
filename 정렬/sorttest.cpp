#include<stdio.h>
#include<stdlib.h>

int equalArray(int arr[], int find[], int size){
	int i;
	for(i = 0; i < size; i++){
		if(arr[i] != find[i]){
			return 0;
		}
	}
	
	return 1;
}

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int insertSort(int arr[], int find[], int size){
	int i;
	int loc, newItem;
	
	for(i = 2; i < size ;i++){
		loc = i - 1;
		newItem = arr[i];
		
		while(1 <= loc && newItem < arr[loc]){
			arr[loc + 1] = arr[loc];
			loc--;
			printArray(arr, size);
			if(equalArray(arr, find, size) == 1){
				return 1;
			}
		}
		if((loc + 1) != i){
			arr[loc + 1] = newItem;
		}
		printArray(arr, size);
		if(equalArray(arr, find, size) == 1){
			return 1;
		}
	}
	
	return 0;
}

int main() {
	int size;

	int i, j;

	scanf("%d", &size);

	int* num = (int*)malloc(sizeof(int) * size);
	int* find = (int*)malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) {
		scanf("%d", &num[i]);
	}
	
	for (i = 0; i < size; i++) {
		scanf("%d", &find[i]);
	}
	
	printf("%d", insertSort(num, find, size));


	return 0;
}
