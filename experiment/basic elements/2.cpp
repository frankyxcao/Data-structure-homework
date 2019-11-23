//该函数功能为：输入链表的头指针，将该链表的数据存入filename.txt
void output(node *head)
{
node *p=head->next;
FILE *w =fopen("filename.txt(你要存入的文件)","w");
if(w==NULL)
{
    printf("文件打开失败");
    return; 
}
//链表数据存入到文件
while(p)
{
    fprintf(w,"%d ",p->data);
    p=p->next; 
} 
fprintf(w,"\n");
fclose(w);
return;
}

