#define maxsize 30000 //can read less than maxsize words
int origindata[maxsize] = {0};
int digitgetter(int n)
{
    int counter = 1;
    n = abs(n);
    while (n >= 10)
    {
        n = n / 10;
        counter++;
    }
    return counter;
}

int Pow(int x, int y)
{
    int i;
    int temp = x;
    for (i = 0; i < y; i++)
    {
        x = x * temp;
    }
    return x;
}

int inputdecter()
{
    FILE *fp = NULL;
    char s[maxsize];
    //	int final[maxsize] = {0};
    char temp;

    int i = 0, j = 0, counter = 0;
    int changer, changertemp, changercounter = 0;

    fp = fopen(".\\res/source.txt", "r"); //open file

    if (fp == NULL)
    {
        printf("Failed to open the file!"); //open file failed XD
        return 1;
    }

    else
        while ((temp = fgetc(fp)) != EOF)
        {
            s[i] = temp;
            //	printf("%d\n" ,s[i]);//test point
            i++;
            counter++;
        }

    fclose(fp);
    s[counter] = '\0';

    for (i = 0; i < counter; i++)
    { //for chinese words
        changer = s[i];
        if (changer < 0)
        {
            changertemp = s[i + 1];
            origindata[j] = changer * Pow(10, digitgetter(changer)) + changertemp * 10 - digitgetter(changer); //rough machining code
            j++;
            i++;
            changercounter++;
        }

        else
        {
            origindata[j] = changer;
            j++;
            changercounter++;
        }
    }
    i = 0;
    /*
	while(origindata[i]!='\0'){
		printf("%d\n" , origindata[i]);
		i++;
	}
	printf("----------------------------------------\n");*/
    //test point
    return 0;
}
