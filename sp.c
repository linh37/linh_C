#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	int masp;
	int gia;
	int soluong;
	char ten[30];
	struct node *next;
}node;
node *first;
int i;
node *nhap(node *s, int ma ,int za,int sl,char name[])
{
  node *temp,*temp1,*temp2;
  int j=0;
  temp=(node *)malloc(sizeof(node));
  temp->masp=ma;
  temp->gia=za;
  temp->soluong=sl;
  strcpy((temp->ten),name);
   if(first==NULL)
    {
        first=temp;
    	s=first;
    }
  else
    {
    	temp1=first;
    	while(temp1)
    	{
    		if(temp->gia < temp1->gia)
    			{
    			if(temp1==first)
    				{
    					temp->next=first;
    					first=temp;
    					break;
    				}
    			else
    				{
    				temp->next=temp2->next;
         		    temp2->next=temp;
         		    break;
    				}
    			}
    		temp2=temp1;
    		if(temp1->next==NULL)
    		{
    			temp1->next=temp;
    			break;	
    		}
    		temp1=temp1->next;
    	}
    	
  	}
}
void in()
{
  node *temp;
  temp=first;
  while(temp)
    {
    	printf("%d %d %d %s\n",temp->masp,temp->gia,temp->soluong,temp->ten);
        temp=temp->next;
    }
  printf("\n");
} 
int main()
{
	FILE *f;
	int a,k,ma,za,sl;
	char name[30];
	k=0,a=0;
	node *s,*temp;
	f=fopen("gia.txt","wt");
	while(1)
	{
		do
		{
			if(k==1) printf("nhap ma sp >0\n");
			printf("nhap ma sp: ");
			scanf("%d",&ma);
			k=1;
		}while(ma<0);
		k=0;
		if(ma==0) break;
		do
		{
			if(k==1) printf("nhap gia sp >0\n");
			printf("nhap gia sp: ");
			scanf("%d",&za);
			k=1;
		}while(za<=0);
		k=0;
		do
		{
			if(k==1) printf("nhap so luong sp >0\n");
			printf("nhap so luong sp: ");
			scanf("%d",&sl);
			k=1;
		}while(sl<0);
		k=0;
		printf("nhap vao ten san pham ");
		scanf("%*c");scanf("%[^\n]",name);
		fprintf(f, "%d %d %d %s ",ma,za,sl,name);
		a++;
	}
	fclose(f);
	f=fopen("gia.txt","rt");
	for(i=0;i<a;i++)
	{

		fscanf(f,"%d %d %d ",&ma,&za,&sl);
		fgets(name,30,f);
		name[strlen(name)-1]='\0';
		printf("%d %d %d %s\n",ma,za,sl,name);
		s=nhap(s,ma,za,sl,name);
	}
	fclose(f);
	printf("sau khi sap xep\n");
	in();
}