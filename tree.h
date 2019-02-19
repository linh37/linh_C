#include<stdio.h>
#include<stdlib.h>
#define MAX 99
typedef struct data_type{
  char eng[MAX];
  char viet[MAX];
}data;
typedef struct bitree{
  data x;
  struct bitree *left,*right;
}bi_tree;
typedef bi_tree *tree;
void make_null(tree *Root);
tree create_node(data y);
void insert_tree(tree *Root,data y);
tree search_tree(tree Root,char y[]);
void delete_min(tree *Root);
void delete_node(tree *Root,char y[]);
void display_tree(tree Root);
