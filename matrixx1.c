
#include<stdio.h>
#include<stdlib.h>

int indexFlatArray(int i, int j, int m, int n) {
    return i*n + j;
}

void nhap(int *A,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            printf("nhap so [%d] [%d]:",i+1,j+1);
            scanf("%d",&A[indexFlatArray(i, j, m, n)]);
        }
}
void tong(int *A,int *B,int *C,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            C[indexFlatArray(i, j, m, n)]=A[indexFlatArray(i, j, m, n)]+B[indexFlatArray(i, j, m, n)];
        }
}
void tich(int *A,int *B,int *C,int m1,int n1,int m2,int n2)
{
    int i,j,x,y,k,s;
    for(i=0;i<m1;i++)
        for(j=0;j<n2;j++)
        {
            x=0;y=0;s=0;
            for(k=0;k<m2;k++)
            {
                s=s+A[indexFlatArray(i, x, m1, n1)]*B[indexFlatArray(y, j, m2, n2)];
                x++;
                y++;
            }
            C[indexFlatArray(i, j, m1, n2)]=s;
        }
}
void in(int *A,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%5d",A[indexFlatArray(i, j, m, n)]);
        }
        printf("\n");
    }
}
int main()
{
    int m1,m2,n1,n2;
    int *C;
    printf("nhap kich thuoc ma tran A: ");
    scanf("%d %d",&m1,&n1);
    int *A=(int*)malloc(m1 * n1 * sizeof(int));
    printf("nhap ma tran A: \n");
    nhap(A,m1,n1);
    in(A,m1,n1);
    printf("nhap kich thuoc ma tran B: ");
    scanf("%d %d",&m2,&n2);
    printf("%d %d\n", m2, n2);
    int *B=(int*)malloc(m2 * n2 * sizeof(int));
    printf("nhap ma tran B: \n");
    nhap(B,m2,n2);
    in(B,m2,n2);
    if(m1==m2 && n1==n2)
    {
        printf("ma tran tong cua ma tran A va B: \n");
        C=(int *)malloc(m1 * n1 * sizeof(int));
        tong(A,B,C,m1,n1);
        in(C,m1,n1);
    }
    else
    {
        printf("2 ma tran khong the cong\n");
    }
    if(n1==m2)
    {
        printf("ma tran tich cua ma tran A va B: \n");
        int *C=(int *)malloc(m1 * n2 * sizeof(int));
        tich(A,B,C,m1,n1,m2,n2);
        in(C,m1,n2);
    }
    else
    {
        printf("2 ma tran khong the nhan");
    }
    return 0;

}
