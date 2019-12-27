#include <stdio.h>
#include <stdlib.h>
#include "outputfix.h"
#include "Output.h"

int main(){
	inputfix();
	FILE*fp = fopen(".\\res/Statistic.txt", "r");
//	FILE*fp1 = fopen(".\\output/test.txt","w");
	if(fp==NULL){
		printf("Failed to open file\n");
		return 1;
	}
	int count = 0;
	char flag;
	while(!feof(fp))
  {
    flag = fgetc(fp);
    if(flag == '\n')
      count++;
  }
    fclose(fp);
   // printf("%d\n" , count);
    fp = fopen(".\\res/Statistic.txt", "r");
	char temp;
	int tempnumber,tempexchanger;
	char s[20] = {0};
	int i = 0,j,k;
	int counter = 0;
	int ten = 10;
	int a[200000];
	for( i = 0 ; i < 200000 ; i++)
	a[i] = 99999;
	
	while( count != 0 ){
	    k = 0;
	    temp = getc(fp);
	    s[0] = temp;
	    i = 1;
	    ten = 1;
	    counter=0;
	    
		while((temp = getc(fp) )!= '-'){
		s[i] = temp;
		counter++;
		i++;
	}
	tempnumber = 0; 
	if(s[0]=='-'){
		for(j = counter ; j > 0 ; j-- ){
			tempexchanger = s[j] - 48;
			tempnumber +=tempexchanger*ten;
			ten*=10;
		}
		tempnumber*=-1;
		//printf("%d" , tempnumber);//OK
	}
	else{
		for(j = counter ; j >= 0 ; j-- ){
			tempexchanger = s[j] - 48;
			tempnumber +=tempexchanger*ten;
			ten*=10;
		}
		//printf("%d" , tempnumber);//OK
	}
	
	while((temp = getc(fp) ) != '\n'){
		if(temp == '0'){
//			printf("%c\n",temp);
		k = 2*k + 1;
	}
		else if(temp =='1'){
//			printf("%c\n",temp);
		k = 2*k+2;
	        }
	    else{
	    	//printf("break\n");
	    break;
	}
	}

	a[k] = tempnumber;
//	fprintf(fp1,"%d: %d,ak is: %d\n" , k , tempnumber , a[k]);
//	printf("%c" , temp);
	
	count--;

	}
//	printf("finfish\n");
//for( i = 0 ; i < 100 ; i++)
//printf("%d\n" , a[i]);//OK
	fclose(fp);
	FILE* fp2 = fopen(".\\output/bin.dat","r");
	FILE* fpt = fopen(".\\output/Target.txt", "w");
	k = 0;
	while(!feof(fp2)){
		temp = getc(fp);
	//	printf("%c" , temp);//OK
	    if(temp == '0'){
//			printf("%c\n",temp);
		k = 2*k + 1;
	}
		else if(temp =='1'){
//			printf("%c\n",temp);
		k = 2*k+2;
	        }
	        if(a[k]!=99999){
	        	ASCdecode(a[k],fpt);
	        	k = 0;
			}
	}
	fclose(fp2);
	fclose(fpt);
	return 0;
}
