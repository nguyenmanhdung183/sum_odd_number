#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define LEN  10000


void init_input(int len, char *arr) { // tao dau vao random
	FILE* f = fopen("input.txt", "w");
	if (f == NULL) {
		printf("error");
		return;
	} 

	srand(time(NULL));

	int i = 0;
	for (i = 0; i < len; i++) {
		int random_number = (rand() % 9) + 1;

		if (i == len - 1) {// tao so 1 o cuoi mang
			random_number = 1; 
		}

		fprintf(f, "%d", random_number);
		arr[i] = '0'+random_number;
	}


	fclose(f);
	return;

}	

void print_output_txt(char* result) {
	int len = strlen(result);
	//printf("len pot = %d", len);
	FILE* f = fopen("output.txt", "w");
	if (f == NULL) {
		printf("error");
		return;
	}


	int i = 0;
	for (i = 0; i < len; i++) {

		fprintf(f, "%d", result[i] -'0');
	}


	fclose(f);
	return;
}

void print_arr(char* s) {
	for (int i = 0; i < strlen(s); i++) {
		printf("%d", s[i] - '0');
	}
}


void add_1_and_div_2(char* arr, char* result) {
	int len = strlen(arr);
	char temp[LEN + 2]; // gom (n + 1) ky tu
	strcpy(temp, arr);


	//add 1
	int carry = 1;
	int add_number = 1;
	for (int i = len - 1; i >= 0 && carry; i--) {
		int sum = (temp[i] - '0') + add_number;
		temp[i] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry) { // them 1 o dau neu bi tran
		memmove(temp + 1, temp, len + 1);
		temp[0] = '1';
		len++;
	}

	//print_arr(temp);

	//div2
	int j = 0;
	int du = 0;
	for (int i = 0; i < len; i++) {
		int cur = du * 10 + (temp[i] - '0');
		result[j++] = (cur / 2) + '0';
		du = cur % 2;
	}
	result[j] = '\0';

	// xoa so 0 o dau neu co
	int k = 0;
	while (result[k] == '0' && result[k + 1] != '\0') k++;
	if (k > 0) memmove(result, result + k, strlen(result + k) + 1);


	return;
}



int pow_2(char *arr, char* result) {
	int len = strlen(arr);
	int* temp = (int*)calloc(2 * len, sizeof(int));
	if (!temp) {
		printf("error calloc\n");
		exit(1);
	}

	// arr * arr
	for (int i = len - 1; i >= 0; i--) {
		int digit1 = arr[i] - '0';
		for (int j = len - 1; j >= 0; j--) {
			int digit2 = arr[j] - '0';
			temp[i + j + 1] += digit1 * digit2;
		}
	}

	// Xu ly carry tu cuoi mang len dau
	for (int i = 2 * len - 1; i > 0; i--) {
		temp[i - 1] += temp[i] / 10;
		temp[i] %= 10;
	}

	// chuyen tu mang int  sang char
	int start = 0;
	if (temp[0] == 0) start = 1;  //bo qua so 0 o dau neu co

	for (int i = start; i < 2 * len; i++) {
		result[i - start] = temp[i] + '0';
	}
	result[2 * len - start] = '\0';
	print_arr(result);

	free(temp);

	return 0;
}

int main() {
	char arr[LEN+1] = { '0' };
	char result_1[LEN + 2] = { '0' };
	char resul_2[2*(LEN + 2)] = { '0' };


	init_input(LEN, arr);

	//strcpy(arr, "5");

	//so le -> result = (((n+1)/2)^2) 

	add_1_and_div_2(arr, result_1); // tinh (n+1)/2

	pow_2(result_1, resul_2);  //tinh binh phuong


	printf("\n\nresult \n\n");
	print_arr(resul_2);
	printf("\n");

	print_output_txt(resul_2);

	return 0;
}