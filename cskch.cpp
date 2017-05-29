#include <stdio.h>
#include "countSketch.h"

void usage(){
	printf("-f ���̓t�@�C����");
	printf("\n");
}

int main(int argc, const char **argv){
	char str[SIZE_T];
	FILE *fp;

	if(argc==3 && argv[1][0]=='-' && argv[1][1]=='f'){
		fp=fopen(argv[2], "r");
		if(!fp){
			perror("���݂��Ȃ��t�@�C�����ł��B");
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
		printf("�ǂ̕��������H:");
		scanf("%s", str);
		printf("%d��\n", show_table((unsigned char*)str));
	}

	return EXIT_SUCCESS;
}

