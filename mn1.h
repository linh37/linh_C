#include <stdio.h>

typedef struct _node *node;
struct _node {
    Ntype value;
    node next;
};
typedef struct _linked_list {
    node head;
    long length;
} *linked_list;

linked_list createLinkedList() {
    linked_list m = malloc(sizeof(struct _linked_list));
    m->head = NULL;
    m->length = 0;
    return m;
}

node makeNode(Ntype data) {
    node a = malloc(sizeof(struct _node));
    a->value = data;
    a->next = NULL;
    return a;
}

node findEnd(linked_list c) {
    node end = c->head;
    if (end == NULL) {
        printf("Danh sach rong.\n");
        return NULL;
    } else {
        while (end->next != NULL) {
            end = end->next;
        }
        return end;
    }
}

void push(linked_list l, Ntype data) {
    node b = makeNode(data);
    if (l->head == NULL) {
        l->head = b;
        l->length++;
    } else {
        node end = findEnd(l);
        end->next = b;
    }
}
void unshift(linked_list l, Ntype data) {
    node b = makeNode(data);
    b->next = head;
    l->head = b;
}

void print(linked_list l) {
    node cur = l->head;
    while (cur != NULL) {
        printNode(cur->value);
        cur = cur->next;
    }
}
