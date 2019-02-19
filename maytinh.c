#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/mystring.h"
#define MAXLEN 100
typedef struct stackelementtype
{
  char s[10];
} stackelementtype;

typedef struct dlistelementtype
{
  char s[10];
} dlistelementtype;

#include "../lib/stack.h"
#include "../lib/dlllib.h"
stacktype stack;
dlisttype li1, li2;

void poptoantu(stacktype *, char);
void hauto();
int strchar(char *, char);
int uutien(char);
void printcur();
stackelementtype dlisttostack(dlistelementtype a);
dlistelementtype stacktodlist(stackelementtype a);
int ketqua(int, int, char);
void menu1();
void menu2();
void menu3();

void MENU(char *);
void freeall()
{
  deletelist(&li1);
  deletelist(&li2);
  deletestack(&stack);
}

int main()
{
  char menu;
  do {
    MENU(&menu);
    switch (menu)
      {
      case '1': menu1(); break;
      case '2': menu2(); break;
      case '3': menu3(); break;
      case '4': printf("\nKet thuc chuong trinh. Goodbye!\n");
      }
  } while (menu != '4');
  freeall();
}
///////////////////////////////////////////////////
void MENU(char *c)
{
  char str_tacGia[50]="Tac gia: Nguyen Phuc Long - VNC K58",str_chuongTrinh[40]="Nokia DB";
  int len_tg, len_ct, i, j;
  len_tg = strlen(str_tacGia);
  len_ct = strlen(str_chuongTrinh);
  printf("\n");  for (i=1;i <= len_tg + len_ct + 31;i++) printf("#");
  printf("\n#\t %s\t\t %s\t #",str_chuongTrinh,str_tacGia);  printf("\n");
  for (i=1;i <= len_tg + len_ct + 31;i++) printf("#");  printf("\n");
  for (i=1;i<= (len_tg + len_ct + 26)/2;i++) printf(" ");
  printf("MENU");
  printf("\n1, Nhap phep toan");
  printf("\n2, In dang hau to");
  printf("\n3, Ket qua");
  printf("\n4, Thoat");
  printf("\n\tBan chon: ");
  scanf("%c",c); DEL();
  while (!(*c=='1'|| *c=='2' ||*c=='3' ||*c=='4'))
    {
      printf("\nBan chon sai. Chon lai: ");
      scanf("%c",c);
      DEL();
    }
}

int strchar(char s[MAXLEN], char c)
{
  int i=0;
  while (s[i] != '\0')
    {
      if (s[i] == c) return 1;
      i++;
    }
  return 0;
}

int uutien(char c)
{
  switch (c)
    {
    case '+':
    case '-': return 0;
    case '*':
    case '/': return 1;
    case '^': return 2;
    case ')': return -1;
    case '(': return -1;
    }
}

void poptoantu(stacktype *top, char toantu)
{
  int temp1, temp2;
  char c, c2;
  dlistelementtype a;
  stackelementtype b;
  c = toantu;
  temp1 = uutien(c);
  if (c == '(') temp1 = 10;
  while (1)
    {
      if (isempty(stack)) break;
      c2 = elementtop(stack).s[0];
      temp2 = uutien(c2);
      if (temp1 < temp2)
	{
	  a = stacktodlist(pop(&stack));
	  makelist(&li2,a);
	  continue;
	}
      if (temp1 == temp2 && strchar("+-*/",c))
	{
	  a = stacktodlist(pop(&stack));
	  makelist(&li2,a);
	  continue;
	}
      if (temp1 == temp2 && c == ')')	
	pop(&stack);	
      break;
    }
}
void hauto()
{
  int i;
  i = 0;
  char s2[MAXLEN], toantu;
  stackelementtype stacktemp;
  dlistelementtype dlisttemp;
  if (li1.head == NULL) menu1();
  if (li2.head != NULL) if (li2.head->prev != NULL) printf("Khac NULL\n");
  deletelist(&li2);
  for (cur = li1.head; cur != NULL; cur = cur->next)
    {
      strcpy(s2,cur->element.s);
      if (s2[0] >= '0' && s2[0] <= '9')
	{
	  makelist(&li2,cur->element);
	}
      else
	{
	  stacktemp = dlisttostack(cur->element);
	  toantu = stacktemp.s[0];
	  if (!isempty(stack))
	    poptoantu(&stack, toantu);
	  if (toantu != ')') push(&stack,stacktemp);
	}
      i++;
    }
  while (!isempty(stack))
    {
      dlisttemp = stacktodlist(pop(&stack));
      makelist(&li2,dlisttemp);
    }
}

void printcur()
{
  printf("%s",cur->element.s);
}

stackelementtype dlisttostack(dlistelementtype a)
{
  stackelementtype b;
  strcpy(b.s,a.s);
  return b;
}

dlistelementtype stacktodlist(stackelementtype a)
{
  dlistelementtype b;
  strcpy(b.s,a.s);
  return b;
}

void menu1()
{
  freeall();
  dlistelementtype el;
  printf("Nhap phep tinh: ");
  while (1)
    {
      scanf("%s",el.s);
      makelist(&li1,el);
      char c = getchar();
      if (c == '\n') break;
    }
}

void menu2()
{
  hauto();
  printf("Dang hau to: ");
  traverse(li2,printcur);
  printf("\n");
}

void menu3()
{
  char c;
  int a, b, kq;
  stackelementtype el, el2;
  deletestack(&stack);
  if (li2.head == NULL) hauto();
  for (cur = li2.head; cur != NULL; cur = cur->next)
    {
      c = cur->element.s[0];
      if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
	{
	  if (isempty(stack))
	    {
	      printf("Loi, thua toan tu %c\n",c);
	      freeall();
	      return;
	    }
	  el2 = pop(&stack);
	  b = atoi(el2.s);
	  if (isempty(stack))
	    {
	      printf("Loi, thua toan tu %c\n",c);
	      freeall();
	      return;
	    }
	  el2 = pop(&stack);
	  a = atoi(el2.s);
	  if (c == '/' && b == 0)
	    {
	      printf("Khong the chia cho 0\n");
	      return;
	    }
	  kq = ketqua(a,b,c);
	  snprintf(el.s,10,"%d",kq);
	  push(&stack,el);
	}
      else
	push(&stack, dlisttostack(cur->element));
    }
  el2 = pop(&stack);
  traverse(li1, printcur); printf(" = %s\n",el2.s);
}

int ketqua(int a, int b, char c)
{
  switch (c)
    {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    case '^': return pow(a,b);
    }
}
