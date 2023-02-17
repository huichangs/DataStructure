#include<stdio.h>
#include<stdlib.h>

typedef int element;

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int selectSort(element arr[], int size){
	int i,j,min;
	int temp = 0;
	for(i = 0; i < size - 1; i++){
		min  = i;
		for(j = i+1; j < size; j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

int bubbleSort(element arr[], int size){
	int i,j,temp,count = 0;
	for(i = 0; i < size; i++){
		for(j = 0; j < size -i -1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count++;
			}
		}
	}
	printf("%d", count);
}

int insertSort(element arr[], int size){
	int i,j,temp;
	int min;
	for(i = 0; i < size; i++){
		for(j = i; j > 0; j--){
			if(arr[j-1] > arr[j]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main(){
	int size;
	
	int i,j;
	
	scanf("%d", &size);
	
	element* num = (element*)malloc(sizeof(element) * size);
	
	for(i = 0; i < size; i++){
		scanf("%d", &num[i]);
	}
	
	bubbleSort(num, size);
	printArray(num, size);
	
	printf("%d", 9 /10);
	

	return 0;
}
