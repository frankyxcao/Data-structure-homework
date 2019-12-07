#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct CCount)
struct CCount
{
    int data;
    int dcount;
    struct CCount*next;
};

int fstar(struct CCount*ahead,int adate)//present address
{
	ahead->data = adate;
	ahead->dcount = 1;
	
	struct CCount* p1;
	p1 = (struct CCount*) malloc(LEN);
	p1->data = 99999;
	ahead->next = p1;
    /*int key1=0;int key=0;
    while(ahead!=NULL)
    {
        if(adate!=ahead->date)
            {key++;}
            ahead=ahead->next;
            key1++;
    }
    if(key==key1)*/
        return 0;
}
int repeatcompare(struct CCount*ahead,int data){
    struct CCount* p;
    p = (struct CCount*) malloc(LEN);
    p = ahead;
    while(p->data!=99999){
    	
    	if(p->data == data){
    	p->dcount++;
    	return 1;
    }
    	p = p->next;
	}
	
	return 0;
}
struct CCount*creat()//´ý¶¨
{
	int i, j, k = 0, strlen = 0;
	
	if(sizeof(origindata) == 0){
		printf("No data!\n");
		return;
	}
	
	struct CCount* head;
	struct CCount* p;
	p = (struct CCount*) malloc(LEN);
	struct CCount* p1;
	p1 = (struct CCount*) malloc(LEN);
	p1->data = 99999;
	p->data = origindata[0];
	p->dcount = 1;
	p->next=p1;
	head = p;
	//-------------------------------------------------------------
	
	while(origindata[k+1] != '\0'){
		//printf("%d: processed\n" , k); //test point1
		k++;
		if(repeatcompare(head, origindata[k] )){
	
			continue; //repeat
	}
		fstar(p->next,origindata[k]); //brand new!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		
		p = p->next;
		
	}
	p = head;
/*	printf("----------------------------------------------\n");
	while(p->data != 99999){
		printf("%d num: %d\n" , p->data, p->dcount);
		p = p->next;
	}*/ //test point
    return(head);
}
