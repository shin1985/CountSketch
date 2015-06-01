#include <stdio.h>
#include "countSketch.h"

void usage(){
	printf("-f 入力ファイル名");
	printf("\n");
}

int main(int argc, const char **argv){
	char str[SIZE_T];
	FILE *fp;

	if(argc==3 && argv[1][0]=='-' && argv[1][1]=='f'){
		fp=fopen(argv[2], "r");
		if(!fp){
			perror("存在しないファイル名です。");
			return  EXIT_FAILURE;
		}
	}
	else{
		usage();
		return EXIT_SUCCESS;
	}
	init();

	while(fgets(str, SIZE_T, fp)!=NULL){
		insert_table((unsigned char*)str);
	}
	fclose(fp);

	while(1){
		printf("どの文字を取る？:");
		scanf("%s", str);
		printf("%d個\n", show_table((unsigned char*)str));
	}

	return EXIT_SUCCESS;
}

