#include <stdio.h>
void ASCdecode(int data, FILE *fp)
{
    int datasc[2], c, i;
    if (data < 0)
    {
        c = (data % 10);
        datasc[1] = (((data - c) % 1000) / 10);
        datasc[0] = (data - 10 * datasc[1] - c) / 1000;
        for (i = 0; i < 2; i++) //ÿ����ASCLL�����һ������
        {                       //����196��227���'��'��186��195���'��'��194��240���'��'
            fprintf(fp, "%c", datasc[i]);
        }
    }

    else
        fprintf(fp, "%c", data);
    return;
}
