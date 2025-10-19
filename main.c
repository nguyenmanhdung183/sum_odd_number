#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000


/***************************************************************************************
Funcion name: make_input()
Input
	- None
Output
	- string is ininitialized

Return 
	-None

Desription: This fucnion create random number in string format ưith length equal to input len, write it to txt file

***************************************************************************************/
void make_input()
{

    FILE *file;
    file = fopen("input.txt", "w");
    if(file == NULL){
        printf("error\n");
        exit(0);
    }


    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            fprintf(file, "%d", 1);
            break;
        }
        fprintf(file, "%d", (rand() % 9) + 1);
    }
    fclose(file);
    return;
}


/***************************************************************************************
Funcion name: read_input()
Input
	- char *a : string contain number in char format
Output
	- string is ininitialized

Return 
	-None

Desription: This fucnion read input from txt
***************************************************************************************/
void read_input(char *a)
{

    FILE *file;
    file = fopen("input.txt", "r");
    if(file == NULL){
        printf("error\n");
        exit(0);
    }

    int count = 0;
    int i = 0;
    while (EOF != fscanf(file, "%c", &a[i++]))
    {
        count++;
    }

    printf("count = %d\n", count);
    a[N + 1] = '\0';
    fclose(file);

    return;
}

/***************************************************************************************
Funcion name: read_input()
Input
	- char *a : string contain number in char format
Output
	- string is ininitialized

Return 
	-None

Desription: This fucnion print ouput to txt
***************************************************************************************/
void print_ouput_txt(char *a){
        FILE *file;
    file = fopen("out.txt", "w");
        if(file == NULL){
        printf("error\n");
        exit(0);
    }

    fprintf(file, "%s", a);

    fclose(file);

    return;

}

/***************************************************************************************
Funcion name: print_arr()
Input
	- char *arr : string contain number in char format
Output
	- None

Return 
	-None

Desription: This fucnion write input to terminal

*************************************************************************************/
void print_arr(char *arr)
{

    printf("\nprint_arr\n%s\n", arr);
    return;
}

/*********************************************************************** 
Funcion name: add_1()
Input
	- char *arr : string contain number in char format
	- char *arr1 :output string to store new result

Output
	- result: output string to store the result

Return 
	-None

Desription:  This function calculates (n + 1)  for a large number represented as a string.

************************************************************************/
void add_1(char *arr2, char *arr1)
{

    strcpy(arr2, arr1);

    int len = strlen(arr2);
    // printf("len arr2 = %d\n", strlen(arr2));

    printf("\n------\n");
    print_arr(arr2);
    int carry = 0;
    int add_value = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        // print_arr(arr2);
        int sum = arr2[i] - '0' + add_value + carry;
        // printf("\nsum = %d\n", sum);
        add_value = 0;
        if (sum > 9)
        {
            carry = 1;
            arr2[i] = (sum % 10) + '0';
        }
        else
        {
            carry = 0;
            arr2[i] = sum + '0';
            break;
        }
    }

    if (carry)
    {
        memmove(arr2 + 1, arr2, strlen(arr2) + 1);
        arr2[0] = '1';
    }

    print_arr(arr2);

    return;
}


/*********************************************************************** 
Funcion name: div_2()
Input
	- char *a : string contain number in char format
Output
	- result: output string to store the result

Return 
	-None

Desription:  This function calculates x  / 2 for a large number represented as a string.

************************************************************************/

void div_2(char *a)
{
    int len = strlen(a);
    // char *arr1 = (char *)malloc(len * sizeof(char)); // luu update a
    char *arr2 = (char *)malloc(len * sizeof(char)); // luu ket qua

    if ((arr2 == NULL))
    {
        printf("error malloc div2");
        exit(0);
    }

    int thuong;
    int du;
    int so_chia = 2;
    // strcpy(arr1, a);
    int idx_arr2 = 0;

    int so_du = 0;
    for (int i = 0; i < len; i++)
    {
        int temp = so_du * 10 + a[i] - '0';
        arr2[idx_arr2++] = (temp / 2) + '0';
        so_du = temp % 2;
    }

    arr2[idx_arr2] = '\0';

    // xoa 0 o dau
    for (int i = 0; i < strlen(arr2); i++)
    {
        if (arr2[i] == '0' && arr2[i + 1] != '0')
        {
            memmove(arr2, arr2 + i + 1, strlen(arr2 - i));
            break;
        }
    }
    strcpy(a, arr2);
    print_arr(arr2);
    return;
}


/***********************************************************************
Funcion name: pow_2()
Input
	- char *a : string contain number in char format
	- char *result :output string to store new result

Output
	- result: output string to store the result

Return 
	-None

Desription:  This function calculates x^2 for a large number represented as a string.

**********************************************************************/
void pow_2(char *a, char *result)
{
    printf("--pow--\n");

    //strcpy(a, "123");
    int len_a = strlen(a);
    int * result_int = (int *) calloc(len_a*2, sizeof(int));



    //printf("result len = %d", strlen(a));
    //print_arr(result);
    int idx_result = len_a*2-1;
    for (int i = len_a - 1; i >= 0; i--)
    {
        for (int j = len_a - 1; j >= 0; j--)
        {
            result_int[i+j+1] += (a[i]-'0')*(a[j]-'0');
            //printf("\nresult %d = %d", i+j+1, result_int[i+j+1]);
        }

    }


    result[len_a*2] ='\0';
    for(int i=len_a*2-1;i>0;i--){

        result_int[i-1] += result_int[i]/10;
        result_int[i] %=10;       
    }

    for(int i=0;i< len_a*2;i++){
        result[i] = result_int[i] +'0';
    }


    for (int i = 0; i <= len_a*2; i++)
    {
        if (result[i] == '0' && result[i + 1] != '0')
        {
            memmove(result, result + i + 1, strlen(result - i));
            break;
        }
    }

    //print_arr(result);


    //print_arr(result);


    return;
}

int main()
{

    char arr[N + 1];
    char arr2[N + 2];
    char arr3[(N + 2) * 2] ={'0'};


    make_input();

    read_input(arr);
    // print_arr(arr);


   // strcpy(arr, "21");

    add_1(arr2, arr);

    div_2(arr2);
    print_arr(arr2);

    pow_2(arr2, arr3);

    print_ouput_txt(arr3);
    printf("\n\nresulr\n\n");
    printf("%s\n", arr3);

    return 0;
}