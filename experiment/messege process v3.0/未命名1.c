#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE*fp;
	fp = fopen(".\\output/Encode.dat", "w");
	char temp;
	int code[20000] ={0};
	int i = 0,counter = 0;
	
	 if (fp == NULL)
    {
        printf("Failed to open the file!"); //open file failed XD
        return 1;
    }
	while((temp = fgetc(fp)) != EOF){
	code[i] = temp-'0';
	i++;	
	counter++;
	}
	
	for(i=0;i<counter-1;i++)
	printf("1%d" , code[i]);
}
