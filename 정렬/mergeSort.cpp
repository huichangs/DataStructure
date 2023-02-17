#include<stdio.h>
#include<stdlib.h>
long long count = 0;

void printArray(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int arr[], int left, int mid, int right){
	int size = right + 1;
	int list[size];
	int i,j,k,l;
	i = left;
	j = mid + 1;
	k = left;
	
	while(i <= mid && j <= right){
		if(arr[i] <= arr[j]){
			list[k++] = arr[i++];
		}
		else{
			list[k++] = arr[j++];
			count += j - k;
		}
	}
	
	if(i > mid){
		for(l = j; l <= right; l++){
			list[k++] = arr[l];
		}
	}else{
		for(l = i; l <= mid; l++){
			list[k++] = arr[l];
		}
	}
	
	for(l = left; l <= right; l++){
		arr[l] = list[l];
	}
	
}

void mergeSort(int arr[], int left, int right){
	int mid;
	
	if(left < right){
		mid = (left + right)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main(){
	int size;
	
	int i;
	
	scanf("%d", &size);
	
	int* num = (int*)malloc(sizeof(int) * size);
	
	for(i = 0; i < size; i++){
		scanf("%d", &num[i]);
	}
	
	mergeSort(num, 0, size - 1);
	
	printf("%lld", count);

	return 0;
}
