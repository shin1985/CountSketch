//============================================================================
// Name        : countSketch.h
// Author      : Shingo.Akiyoshi
// Version     : 0.1(2010)
// Copyright   : master@akishin.netまでお問い合わせください。
// Description : CountSketch in C, Ansi-style
// Memo        : ハッシュ関数がASCIIコードなので、入力文字の無茶はしないこと！
//============================================================================
#include <stdlib.h>
#include <string.h>

#define SIZE_B 256
#define SIZE_T 256

int DATA_TABLES[SIZE_T][SIZE_B];



/* {-1,1}を出力するハッシュ関数 */
int func_s(unsigned char *q){
	if(*q%2==0)
		return 1;
	else
		return -1;
}

/* 位置を決めるハッシュ関数 */
int func_h(unsigned char *q){
	return *q;
}

/* q-sort */
int sort(int *num1, int *num2){
	return *num1-*num2;
}

/* メディアン */
int median(int num[],int len){
	qsort(num, len, sizeof(int), (int (*)(const void*, const void*))sort);
	return num[len/2];

}

/* 初期化 */
void init(){
	memset(DATA_TABLES, 0, sizeof(SIZE_T)*sizeof(SIZE_B));
}

/* 挿入 */
void insert_table(unsigned char *str){
	int p=0;
	while(*(str+p)!='\r' && *(str+p)!='\n' && *(str+p)!='\0'){
		DATA_TABLES[p][func_h( (str+p))]+=func_s( (str+p));
		p++;
	}
}

/* 抽出 */
int show_table(unsigned char *str){
	int p=0;
	int num[SIZE_T];
	while(*(str+p)!='\r' && *(str+p)!='\n' && *(str+p)!='\0'){
		num[p]=DATA_TABLES[p][func_h( (str+p))]*func_s( (str+p));
		p++;
	}

	return median(num, p);
}

