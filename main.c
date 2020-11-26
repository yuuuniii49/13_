#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct keytab {
	int nums;
	char name[20];
};

char *key_data[] = {"int", "float", "return", "if", "for", "while", "goto", "switch", "case", "void", "default", "char", "do"};

int main(void){
	struct keytab keywrds[13] ;
	char filename[20];
	FILE *fp = NULL;
	char word[20] = "";
	int i=0, j, ch, cnt=0;
	
	printf("Input the file name : ");
	scanf("%s", filename);

	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("파일이 열리지 않습니다.\n");
		return 1; 
	}
	else {
		printf("파일이 열렸습니다.\n");
	}
	
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) {
			break;
		}
		else if (isalpha(ch)) {
			word[i] = ch;
			i++;
		}
		else {
			word[i] = '\0';
			for (j=0; j<13; j++) {
				if (strcmp(keywrds[j].name, word) == 0) keywrds[j].nums++;
				
			}
			i = 0;
			strcpy(word, "");
		}
	}
 
	for (j=0; j<13; j++) {
		printf("%s %d\n", keywrds[j].name, keywrds[j].nums);
	}
	
	fclose(fp);
	
	return 0;
}
