//�ú�������Ϊ�����������ͷָ�룬������������ݴ���filename.txt
void output(node *head)
{
node *p=head->next;
FILE *w =fopen("filename.txt(��Ҫ������ļ�)","w");
if(w==NULL)
{
    printf("�ļ���ʧ��");
    return; 
}
//�������ݴ��뵽�ļ�
while(p)
{
    fprintf(w,"%d ",p->data);
    p=p->next; 
} 
fprintf(w,"\n");
fclose(w);
return;
}

