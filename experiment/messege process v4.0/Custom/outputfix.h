#include <stdio.h>
#include <stdlib.h>
char leninput[300000];
int length = 0;
int outfix()
{
    FILE *fp;
    fp = fopen(".\\output/Encode.dat", "r");
    char temp;
    int code[300000] = {0};
    int i = 0, counter = 0;

    if (fp == NULL)
    {
        printf("Failed to open the file!"); //open file failed XD
        return 1;
    }

    while ((temp = fgetc(fp)) != EOF)
    {
        code[i] = temp - '0';
        i++;
        counter++;
    }

    //for(i=0;i<counter;i++)//testpoint OK
    //printf("%d" , code[i]);//testpoint OK
    fp = fopen(".\\output/Encode.dat", "w");
    //	printf("\n");//testpoint OK

    int i1 = 0, j = 0, k = 0;
    int tempm = 0;
    j = counter / 8;
    k = counter - j * 8;
    if(k==0)
    counter = 0;
    else
	counter = 8 - k; //counter is number of 0s in the end
//	printf("%d\n",counter);//
    fprintf(fp, "%d", counter);
    //printf("%d,%d\n",j,k);//testpoint OK
    //printf("%d\n" , counter);//testpoint OK
    i = 0;
    for (i1 = 0; i1 < j; i1++)
    {
        tempm = 0;
        tempm += code[i] * 128;
        i++;
        tempm += code[i] * 64;
        i++;
        tempm += code[i] * 32;
        i++;
        tempm += code[i] * 16;
        i++;
        tempm += code[i] * 8;
        i++;
        tempm += code[i] * 4;
        i++;
        tempm += code[i] * 2;
        i++;
        tempm += code[i] * 1;
        i++;
        //printf("%d\n" , tempm);//testpoint OK
        fprintf(fp, "%c", tempm);
    }
    int a128 = 128;
    int tempcounter = 0;
    tempm = 0;
    if(k!=0){
    while (k != 0)
    {
        tempm += code[i] * a128;

        a128 = a128 / 2;
        i++;
        k--;
        tempcounter++;
    }
    fprintf(fp, "%c", tempm);
}

	fclose(fp);
}

void process(int a){
//	printf("%d: " , a);
	char temp[8];
	int i;
	for( i = 0 ; i < 8 ; i++)
	temp[i]='0';
	i = 7;
	while(a!=0){
		if(a%2==0)
		temp[i]='0';
		else if(a%2==1)
		temp[i]='1';
		i--;
		a/=2;
	}
	for(i = 0 ; i <8;i++){
	//printf("%c" , temp[i]);
	//fprintf(fp,"%c",temp[i]);
	leninput[length] = temp[i];
	length++;
}
//printf("\n");
//	printf("\n");
}

void inputfix()
{
    char temp;
    int tempm;
    FILE *fp;
    int i = 0;
    int counter = 0;
    fp = fopen(".\\res/Encode.dat", "rb");
    if (fp == NULL)
    {
        printf("Failed to open the file!"); //open file failed XD
        return;
    }
    
    else{
	//FILE*fp1;
    //fp1 = fopen(".\\output/test.txt", "w");
    FILE*fp2;
    fp2 = fopen(".\\output/bin.dat", "w");
	short element;
    	fscanf(fp,"%c",&temp);
    	tempm = temp - '0';
    	//printf("%d\n" , tempm);
    //	printf("%c\n" , temp);
    	i = 0;
        while (!feof(fp))
        {
            element = getc(fp);
            //fprintf(fp1,"%2d\n",element);
            process(element);
        }
       for(i=0;i<length-tempm-8;i++){
        //	printf("yes\n");
        	fprintf(fp2,"%c",leninput[i]);
		}
		fclose(fp2);
        return;
    }
    }
