# include <stdio.h>
#include <stdlib.h>
#define maxsize 100

int digitgetter(int n){
	int counter = 1;
	n=abs(n);
	while(n>=10){
		n = n/10;
		counter++;
	}
	return counter;
}
int Pow(int x, int y){
	int i;
	int temp = x;
	for(i=0;i<y;i++){
		x = x*temp;
	}
	return x;
}

int main(){
	FILE *fp = NULL;
	char s[maxsize];
	int final[maxsize] = {0};
	char temp;
	
	int i = 0,j = 0,counter = 0;
	int changer,changertemp,changercounter = 0;
	
	fp = fopen(".\\test.txt","r");
	if(fp == NULL){
		printf("Failed to open the file!");
	return 1; 
}
	
	else
	while((temp = fgetc(fp)) != EOF){
		s[i] = temp;
		i++;
		counter++;
	}
	
	fclose(fp);
	s[counter] = '\0';	
    
	for( i = 0 ;i < counter ;i++){
	    changer = s[i];
	    if(changer<0){
	    	changertemp = s[i+1];
	    	final[j] = changer * Pow( 10 , digitgetter(changer))+changertemp*10-digitgetter(changer);
	    	j++;
	    	i++;
	    	changercounter++;
		}
		
		else{
		final[j] = changer;
		j++;
		changercounter++;
	}
}
    for(i=0;i<changercounter;i++){
    	printf("%d\n" , final[i]);
	}
	
	return 0;
}
