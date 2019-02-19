#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{	
	int giobd;
	char congviec[30];
	char tinhchat[20];
	struct node *next;	
}node;
typedef struct tree
{
	int ngay;
	struct tree *trai;
	struct tree *phai;
	struct node *dau;
}tree;
tree *them(tree *root, int x);
void NLR(tree* root);
int check(tree *root,int x);
tree *bo_xung(tree *root,int x,int tg);
void in(node *dau);
void in_theo_ngay(tree *root,int x);
node *nhap_cong_viec(node *s1, tree *root, int tg, char cv[], char tc[])
{
	node *temp,*temp1,*temp2;
	temp=(node*) malloc(sizeof(node));
	temp->giobd=tg;
	strcpy(temp->congviec,cv);
	strcpy(temp->tinhchat,tc);
	if(root->dau==NULL)
	{
		root->dau=temp;
		s1=root->dau;
	}
	else
	{
		temp1=root->dau;
		while(temp1)
		{
			if(tg < temp1->giobd)
			{
				if(temp1==root->dau)
				{
					temp->next=root->dau;
					root->dau=temp;
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
int check(tree *root,int x)
{
	if (root == NULL) return 1;
    else if (root-> ngay > x)	return check(root->trai,x);   
    else if (root-> ngay < x)	return check(root->phai,x);
    else if (root-> ngay ==x)	return 0;
}

tree *them(tree *root, int x)      //wakarimasuka ?
    {
    	int tg;
    	char cv[30],tc[20];
    	node *s1;
        if (root == NULL)
        {
        	root = (tree *)malloc(sizeof(tree));
            root -> ngay= x;
        	while(1)
        	{	
            	printf("nhap thoi gian: ");
            	scanf("%d",&tg);
            	if(tg==0) break;
            	printf("nhap cong viec: ");
            	scanf("%*c");scanf("%[^\n]",cv);
    			printf("nhap tinh chat cong viec: ");
    			scanf("%*c");
    			gets(tc);
    		   	s1=nhap_cong_viec(s1,root,tg,cv,tc);
    		   	printf("\n");
       		}
       		root -> trai = NULL;
       		root -> phai = NULL;
       		return root;
        }
        else if (root->ngay > x)	root->trai=them(root->trai,x);   
        else if (root->ngay < x)	root->phai=them(root->phai,x);
        else if (root->ngay ==x)	{printf("trung ngay : \n");return root;}
    }
tree *bo_xung(tree *root,int x,int tg)
{	
	node *s1;
	char cv[30],tc[20];
	if (root == NULL)
        {
        	printf("khong co ngay de bo xung: ");
        	return root;
       	}
    else if (root-> ngay > x)	root->trai=bo_xung(root->trai,x,tg);   
    else if (root-> ngay < x)	root->phai=bo_xung(root->phai,x,tg);
    else if (root-> ngay ==x)	
    	{
    		printf("nhap cong viec: ");
			scanf("%*c");
			gets(cv);
    		printf("nhap tinh chat cong viec: ");
    		gets(tc);
    		s1=nhap_cong_viec(s1,root,tg,cv,tc);
    		return root;
    	}
}  
void in_theo_ngay(tree *root,int x)
{
	node *temp;
	if(root->ngay == x)		
		{
			temp=root->dau;
			printf("gio cong viec               ten cong viec          tinh chat cong viec\n");
			while(temp)
			{
				printf("  %8d     %20s   %20s\n",temp->giobd, temp->congviec, temp->tinhchat);
				temp=temp->next;
			}
		}
	else if (root->ngay > x)	in_theo_ngay(root->trai,x);
    else if (root->ngay < x)	in_theo_ngay(root->phai,x);
}
tree *xoa_cay(tree *root, int x)     // test sau
{
	
    if (root==NULL) return root;
    if (root->ngay > x) root->trai=xoa_cay(root->trai, x);
    if (root->ngay < x) root->phai=xoa_cay(root->phai, x);
    if (root->ngay == x)
    {
    	tree *temp = root;
        if (root->trai == NULL) { root=root->phai; return root; }    // cay chi co cay con phai
        else if (root->phai == NULL) { root=root->trai; return root; }   // cay chi co cay con trai
        else // cay co ca 2 con
        {
            tree *temp1 = root;
            tree *temp2 = temp1->trai;
            // temp1 la cha cua temp, temp la Node trai nhat cua cay con phai cua temp1
            while (temp2->phai != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->phai;
            }
            temp->ngay = temp2->ngay;
            temp->dau = temp2->dau;
        //    temp1->phai = temp2->trai;
            free(temp2);
        }
    }
    return root;
}
void NLR(tree* root)
    {
    	if (root != NULL)
    	{
    		NLR(root->trai);
    		printf("ngay %d: \n", root->ngay);
    		in_theo_ngay(root,root->ngay);printf("\n");
    		NLR(root->phai);
    	}	
    }
int main()
{
	int x,ng,tg;
	tree *root=NULL;
	do
	{	
		printf("1, nhap lich lam viec\n");
		printf("2, bo xung cong viec\n");
		printf("3, xoa lich lam viec\n");
		printf("4, in danh sach theo ngay\n");
		printf("5, thoat \n");
	
		scanf("%d",&x);
		if(x==1)
		{
			while (1)
   			{
   				
        		printf("Nhap vao ngay: ");
        		scanf("%d", &ng);
        		if (ng == 0) break;
        		root=them(root,ng);
	    	}
		}
		if(x==2)
		{
			while(1)
			{
				printf("chon ngay bo xung: ");
				scanf("%d", &ng);
				if(ng==0) break;
				if( check(root,ng)==1 ) 
				{
					printf("bo xung ngay moi la %d: ",ng);
					root=them(root,ng); ///
				}
				else
				{	
					while(1)
					{
						printf("nhap gioi gian ");
						scanf("%d",&tg);
						if(tg==0) break;
						else root=bo_xung(root,ng,tg);
					}
				}
			}
		}
		if(x==3)
		{
			while(1)
			{
				printf("nhap ngay muon xoa: ");
				scanf("%d",&ng);
				if(ng==0) break;
				root=xoa_cay(root,ng);
			}
		}
		if(x==4)
		{
				printf("chon ngay muon in cong viec: \n");
				scanf("%d", &ng);
				if( check(root,ng)==1 ) printf("khong co ngay nay \n");
				else in_theo_ngay(root,ng);					
		}
		if(x==6)
		{
		//printf("%d\n",root->dau->giobd );
		NLR(root);
		}
	}while(x!=5);

}
