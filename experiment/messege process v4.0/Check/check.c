#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE*fp1;
	FILE*fp2;
	fp1 = fopen(".//res\source.txt","r");
	fp2 = fopen(".//output\Target.txt","r");
	
	char temp1 = 0,temp2 = 0;
	while((temp1 = fgetc(fp1)) != EOF && (temp2 = fgetc(fp2)) != EOF){
		if(temp1!=temp2){
			printf("Matching failed!\n");
			return;
		}
	}
	
	printf("Matching succeed!\n");
	system("pause");
	return 0;
} 
