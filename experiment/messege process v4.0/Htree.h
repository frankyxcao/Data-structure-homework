#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ELEMTYPE;
typedef struct HuffmanTree
{
    ELEMTYPE weight;
    int value;
    struct HuffmanTree *lchild;
    struct HuffmanTree *rchild;
} HuffmanNode;

// ������������
HuffmanNode *createHuffmanTree(int *a, int *b, int n)
{
    int i, j;
    HuffmanNode **temp, *hufmTree;
    temp = (HuffmanNode **)malloc(n * sizeof(HuffmanNode));
    for (i = 0; i < n; ++i) // ������a�е�Ȩֵ��������е�weight
    {
        temp[i] = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        temp[i]->weight = a[i];
        temp[i]->lchild = temp[i]->rchild = NULL;
        temp[i]->value = b[i];
    }

    for (i = 0; i < n - 1; ++i) // n-1�κϲ�
    {
        int small1 = -1, small2; // small1��small2�ֱ���Ϊ��С�ʹ�СȨֵ���±�
        for (j = 0; j < n; ++j)  // �Ƚ���С�������±긳��small1��small2��ע�⣺��ӦȨֵδ����С��
        {
            if (temp[j] != NULL && small1 == -1)
            {
                small1 = j;
                continue;
            }
            else if (temp[j] != NULL)
            {
                small2 = j;
                break;
            }
        }
        if (small1 > small2)
        {
            int t = small1;
            small1 = small2;
            small2 = t;
        }
        for (j = small2; j < n; ++j) // �Ƚ�Ȩֵ��Ų��small1��small2ʹ֮�ֱ��Ϊ��С�ʹ�СȨֵ���±�
        {
            if (temp[j] != NULL)
            {
                if (temp[j]->weight < temp[small1]->weight)
                {
                    small2 = small1;
                    small1 = j;
                }
                else if (temp[j]->weight < temp[small2]->weight)
                {
                    small2 = j;
                }
            }
        }
        hufmTree = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        hufmTree->weight = temp[small1]->weight + temp[small2]->weight;
        hufmTree->lchild = temp[small1];
        hufmTree->rchild = temp[small2];
        hufmTree->value = 99999; //for test,maybe unworked-------------------------------------

        temp[small1] = hufmTree;
        temp[small2] = NULL;
    }
    return hufmTree;
}

// �ݹ���й���������
void HuffmanCode(HuffmanNode *hufmTree, int depth, int *code, FILE *fp) // depth�ǹ������������
{

    if (hufmTree)
    {
        if (hufmTree->lchild == NULL && hufmTree->rchild == NULL)
        {
            //printf("%d�Ĺ���������Ϊ ",  hufmTree->value);
            fprintf(fp, "%d-", hufmTree->value);
            int i;
            for (i = 0; i < depth; ++i)
            {
                //printf("%d", code[i]);
                fprintf(fp, "%d", code[i]);
            }
            //printf("\n");
            fprintf(fp, "\n");
        }
        else
        {
            code[depth] = 0;
            HuffmanCode(hufmTree->lchild, depth + 1, code, fp);
            code[depth] = 1;
            HuffmanCode(hufmTree->rchild, depth + 1, code, fp);
        }
    }
}

void coding(HuffmanNode *hufmTree, int depth, int *code, FILE *fp, int target)
{
    if (hufmTree)
    {

        //	fprintf(fp,"test\n");
        if (hufmTree->value == target)
        {
            int i;
            for (i = 0; i < depth; ++i)
            {
                //	printf("%d", code[i]);
                //	fprintf(fp,"test");
                fprintf(fp, "%d", code[i]);
            }
            //printf("\n");
            //fprintf(fp,"\n");
            return;
        }

        else
        {
            code[depth] = 0;
            coding(hufmTree->lchild, depth + 1, code, fp, target);
            code[depth] = 1;
            coding(hufmTree->rchild, depth + 1, code, fp, target);
        }
    }
    //	printf("yes");//test point
    return;
}

void decode(HuffmanNode *hufmTree, FILE *fpread, FILE *fpwrite)
{   //fpread is fp1
    //--------------------------way1-------------------------------------------------------------
    char a[200000];
    int num[200000];
    int i = 0;
    char temp;
    while ((temp = fgetc(fpread)) != EOF)
    {
        a[i] = temp;
        i++;
    }

    a[i] = '\0';
    i = 0;
    /*
	while(a[i] != '\0'){
	printf("%c" , a[i]);
	i++;
	}
	
	for (i=0; i<strlen(a); ++i)
    {
        if (a[i] == '0')
            num[i] = 0;
        else
            num[i] = 1;
    }
*/
    HuffmanNode *tempTree = NULL;
    if (hufmTree)
    {
        i = 0; // �����ѽ���01���ĳ���
        while (i < strlen(a))
        {
            tempTree = hufmTree;
            while (tempTree->lchild != NULL && tempTree->rchild != NULL)
            {
                if (a[i] == '0')
                {
                    tempTree = tempTree->lchild;
                }
                else
                {
                    tempTree = tempTree->rchild;
                }
                ++i;
            }
            ASCdecode(tempTree->value, fpwrite);
            // printf("%c", tempTree->value);     // ���������Ӧ�����ַ�
        }
    }

    //------------------------------way2----------better but no worked XD----------------------------------------------
    /*	HuffmanNode* temptree;
	char temp;
	fscanf(fpread,"%c",&temp);


	while(temp!=EOF){
		temptree = hufmTree;
		
		while(temptree->lchild != NULL && temptree->rchild != NULL && temp !=EOF)
            {
                if (temp == '0')
                {
                    temptree = temptree->lchild;
                } 
				
				else if(temp = '1')
                {
                    temptree = temptree->rchild;
                }
            fscanf(fpread,"%c",&temp);
            }
            
            fprintf(fpwrite,"%d", temptree->value);     // ���������Ӧ�����ַ�
	}*/
}

int Htree(struct CCount *p)
{
    int i, n, temp;
    int string[20000];
    n = counter1;
    int *arr;
    arr = (int *)malloc(n * sizeof(ELEMTYPE));
    //	printf("������%d��Ҷ�ӽ���Ȩֵ������Դ�����ַ���\n", n);
    for (i = 0; i < n; ++i)
    {
        //printf("��%d��------------------------------",i+1);
        //printf("%d\n" , p->data);
        arr[i] = p->dcount;
        string[i] = p->data;
        //printf("%d %d\n" , string[i],arr[i]);//test point
        fflush(stdin);
        p = p->next;
        //scanf("%d", &arr[i]);//weight
        //scanf("%d", &string[i]);//
    }

    HuffmanNode *hufmTree = NULL;
    hufmTree = createHuffmanTree(arr, string, n);
    int code[20000];
    //	printf("\n��Ҷ�ӽ��Ĺ���������Ϊ��\n");
    FILE *fp;
    fp = fopen(".\\output/Statistic.txt", "w"); //�����ļ�
    HuffmanCode(hufmTree, 0, code, fp);
    fclose(fp);

    FILE *fp1;
    fp1 = fopen(".\\output/Encode.dat", "w");
    //fprintf(fp1,"test");	//test point
    i = 0;

    while (origindata[i] != '\0')
    {
        coding(hufmTree, 0, code, fp1, origindata[i]);
        i++;
    }
    fclose(fp1);
    outfix();
    inputfix();
    FILE *fp2;
    fp2 = fopen(".\\output/bin.dat", "r");
    FILE *fp3;
    fp3 = fopen(".\\output/Target.txt", "w");
    //	fprintf(fp2,"666");//test
    decode(hufmTree, fp2, fp3);
    printf("--------------------Decoding success!--------------------\n");
    /*
    int a[200000];
    i = 0;
    char temp1;

    while( ( temp1 = fgetc(fp2) ) != EOF){
    	a[i] = temp1;
    	printf("%c" , temp1);
    	i++;
	}
	a[i] = '\0';
	i = 0;
	
	while(a[i]!='\0'){
//	printf("------------------------\n");
//	printf("%d" , a[i]);
	i++;
	}
	*/
    return 0;
}

