/*************************************************************************
	> File Name: linklist.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年06月06日 星期三 18时09分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkList {
    LinkNode *head;
    int length;
} LinkList;

LinkList *init() {
    LinkList *p = (LinkList *)malloc(sizeof(LinkList));
    p->length = 0;
    return p;
}

LinkNode *getNewNode(int data) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = data;
    p->next = NULL;
    return p;
}

int insert(LinkList *list, int data, int ind) {
    if (ind < 0 || ind > list->length) return 0;
    LinkNode ret, *p;
    ret.next = list->head;
    p = &ret;
    while (ind--) {
        p = p->next;
    }
    LinkNode *new_node = getNewNode(data);
    new_node->next = p->next;
    p->next = new_node;
    list->head = ret.next;
    list->length++;
    return 1;
}

void clear(LinkList *list) {
    LinkNode *head = list->head;
    while (head) {
        LinkNode *p = head->next;
        free(head);
        head = p;
    }
    free(list);
    return;
}

void output(LinkList *list) {
    LinkNode *head = list->head;
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("null\n");
}

int main() {
    LinkList *linklist = init();
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int data = rand() % 100, ind = rand() % (i + 2) - 1;
        printf("%d : insert(%d, %d) = ", i, data, ind);
        insert(linklist, data, ind);
        printf("insert end\n");
        fflush(stdout);
        output(linklist);
    }
    free(linklist);
    return 0;
}
