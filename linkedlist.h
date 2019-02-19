#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node *node;
struct _node {
    Ntype *value;
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
    a->value = malloc(sizeof(Ntype));
    *(a->value) = data;
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
    b->next = l->head;
    l->head = b;
}

void printLinkedList(linked_list l, void (*printNode)(int, Ntype)) {
    node cur = l->head;
    int idx = 0;
    while (cur != NULL) {
        printNode(idx, *(cur->value));
        cur = cur->next;
        idx++;
    }
}

node findMin(linked_list l, int (*cmp)(Ntype, Ntype)) {
    node cur, min;
    cur = l->head;
    min = l->head;

    while (cur != NULL) {
        if (cmp(*(min->value), *(cur->value)) > 0) min = cur;
        cur = cur->next;
    }

    return min;
}

node findMax(linked_list l, int (*cmp)(Ntype, Ntype)) {
    node cur, max;
    cur = l->head;
    max = l->head;

    while (cur != NULL) {
        if (cmp(*(max->value), *(cur->value)) < 0) max = cur;
        cur = cur->next;
    }

    return max;
}

node findMaxFromNToEnd(node n, int (*cmp)(Ntype, Ntype)) {
    node cur, max;
    cur = n;
    max = n;

    while (cur != NULL) {
        if (cmp(*(max->value), *(cur->value)) < 0) max = cur;
        cur = cur->next;
    }

    return max;
}

node findMinFromNToEnd(node n, int (*cmp)(Ntype, Ntype)) {
    node cur, min;
    cur = n;
    min = n;

    while (cur != NULL) {
        if (cmp(*(min->value), *(cur->value)) > 0) min = cur;
        cur = cur->next;
    }

    return min;
}

void swapData(node a, node b) {
    Ntype *tmp = a->value;
    a->value = b->value;
    b->value = tmp;
}

// type ASC hoac DESC
void sort(linked_list l, int (*cmp)(Ntype, Ntype), char *type) {
    node i, select;
    i = l->head;
    while (i != NULL) {
        if (strcmp("DESC", type) == 0) {
            select = findMinFromNToEnd(i, cmp);
        } else {
            select = findMaxFromNToEnd(i, cmp);
        }
        swapData(select, i);
        i = i->next;
    }
}

Ntype* find(linked_list l, Ntype key, int (*cmp)(Ntype, Ntype)) {
    node cur;
    cur = l->head;

    while (cur != NULL) {
        if (cmp(key, *(cur->value)) == 0) return cur->value;
        cur = cur->next;
    }

    return NULL;
}

node findNode(linked_list l, Ntype key, int (*cmp)(Ntype, Ntype)) {
    node cur;
    cur = l->head;

    while (cur != NULL) {
        if (cmp(key, *(cur->value)) == 0) return cur;
        cur = cur->next;
    }

    return NULL;
}

void delHead(linked_list l) {
    node first = l->head->next;
    free (l->head);
    l->head = first;
}

void delNode(linked_list l, node prev, node cur) {
    if(cur == l->head){
        delHead(l);
    } else {
        prev->next = cur->next;
        free(cur);
    }
}
