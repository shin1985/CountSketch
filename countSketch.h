//============================================================================
// Name        : countSketch.h
// Author      : Shingo.Akiyoshi
// Version     : 0.1(2010)
// Copyright   : master@akishin.net�܂ł��₢���킹���������B
// Description : CountSketch in C, Ansi-style
// Memo        : �n�b�V���֐���ASCII�R�[�h�Ȃ̂ŁA���͕����̖����͂��Ȃ����ƁI
//============================================================================
#include <stdlib.h>
#include <string.h>

#define SIZE_B 256
#define SIZE_T 256

int DATA_TABLES[SIZE_T][SIZE_B];



/* {-1,1}���o�͂���n�b�V���֐� */
int func_s(unsigned char *q){
	if(*q%2==0)
		return 1;
	else
		return -1;
}

/* �ʒu�����߂�n�b�V���֐� */
int func_h(unsigned char *q){
	return *q;
}

/* q-sort */
int sort(int *num1, int *num2){
	return *num1-*num2;
}

/* ���f�B�A�� */
int median(int num[],int len){
	qsort(num, len, sizeof(int), (int (*)(const void*, const void*))sort);
	return num[len/2];

}

/* ������ */
void init(){
	memset(DATA_TABLES, 0, sizeof(SIZE_T)*sizeof(SIZE_B));
}

/* �}�� */
void insert_table(unsigned char *str){
	int p=0;
	while(*(str+p)!='\r' && *(str+p)!='\n' && *(str+p)!='\0'){
		DATA_TABLES[p][func_h( (str+p))]+=func_s( (str+p));
		p++;
	}
}

/* ���o */
int show_table(unsigned char *str){
	int p=0;
	int num[SIZE_T];
	while(*(str+p)!='\r' && *(str+p)!='\n' && *(str+p)!='\0'){
		num[p]=DATA_TABLES[p][func_h( (str+p))]*func_s( (str+p));
		p++;
	}

	return median(num, p);
}

