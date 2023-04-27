#include<stdio.h>
#include<stdlib.h>
struct names{
	char n1[30];
	char n2[100];
};

int main(){
	//q1
	char c[30] = {0, };	
	scanf("%[^\n]s", c);
	printf("%s", c);
	printf("\n");
	//q2
	int array1[3][3] = {{1, 5, 0} ,{0, 4, 1} ,{3, 6, 5}};
	int array2[3][3] = {{6, 4, 1}, {-1, 5, 3}, {-2, -4, 0}};
	int array3[3][3] = {0, };
	int i, j, k;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			for(k = 0; k < 3; k++){
				array3[i][j] += array1[i][k] * array2[k][j];
			}
		}
	}
	
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", array3[i][j]);
		}
		printf("\n");
	}
	//q3
	struct names name[30] = {0};
	int count = 0;
	FILE* fp = fopen("names.txt", "r");
	
	
	for(i = 0; i < 30; i++){
		fscanf(fp, "%s %[^\n]s", &name[i].n1, &name[i].n2);
	}
	fclose(fp);
	
	for(i = 0; i < 30; i++){
		printf("[%d] %s %s\n", i, name[i].n1, name[i].n2);
	}

	for(i = 0; i < 30; i++){
		printf("%s\n", name[i].n1);
		for(j = 0; j < 30; j++){
			if(name[i].n1[j] == 'M'){
				count++;
			}
		}
	}
	printf("M °¹¼ö : %d\n", count);
	for(i = 0; i < 30; i++){
		printf("%s\n", name[i].n2);
		for(j = 0; j < 100; j++){
			if(name[i].n2[j] == 'M'){
				count++;
			}
		}
	}
	printf("M °¹¼ö : %d", count);
	
	
	return 0;
}
