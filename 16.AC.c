/*************************************************************************
	> File Name: 16.AC.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年08月06日 星期一 11时35分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define BASE 26
#define BEGIN_LETTER 'a'


typedef struct Node {
    int flag;
    char *str;
    struct Node *next[BASE];
    struct Node *fail;
} Node;

Node *get_new_node();
void clear (Node *);
Node* insert(Node *, const char *);
void build_ac(Node *);
void search_ac(Node *, const char *);


int main() {
    Node *root = NULL;
    root = insert(root, "skange");
    root = insert(root, "nihao");
    root = insert(root, "shangke");
    root = insert(root, "gke");
    root = insert(root, "an");
    build_ac(root);
    search_ac(root, "woshishangkenimenaho");
    clear(root);
    return 0;
}


Node *get_new_node() {
    return (Node *)calloc(sizeof(Node), 1);
}

void clear(Node *node) {
    if (node ==NULL) return ;
    for (int i = 0; i < BASE; i++) {
        if (node->next[i] == NULL) continue;
        clear(node->next[i]);
    }
    if (node->flag) free(node->str);
    free(node);
    return;
}

Node *insert(Node *root, const char *str) {
    if (root == NULL) root = get_new_node();
    Node *p = root; 
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BEGIN_LETTER] == NULL) {
            p->next[str[i] - BEGIN_LETTER] = get_new_node();
        }
        p = p->next[str[i] - BEGIN_LETTER];
    }
    p->flag = 1;
    p->str = strdup(str);
    return root;
}

void build_ac(Node *root) {
    #define MAX_N 100000
    if (root ==NULL) return ;
    Node **queue = (Node **)malloc(sizeof(Node *) * MAX_N);
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        Node *node = queue[head++];
        for (int i = 0; i < BASE; i++) {
            if (node->next[i] == NULL) continue;
            Node *p = node->fail;
            while (p && p->next[i] == NULL) {
                p = p->fail;
            }
            if (p == NULL) {
                node->next[i]->fail = root;
            } else {
                node->next[i]->fail = p->next[i];
            }
            queue[tail++] = node->next[i];
            
        }
    }
    free(queue);
    return ;
    #undef MAX_N
}

void search_ac(Node *root, const char *text) {
    Node *p = root;
    for (int i = 0; text[i]; i++) {
        while (p && p->next[text[i] - BEGIN_LETTER] == NULL) {
            p = p->fail;
        }
        if (p == NULL) {
            p = root;
        } else {
            p = p->next[text[i] - BEGIN_LETTER];
        }
        Node *q = p;
        while (q) {
            if (q->flag) {
                printf("find string : %s\n", q->str);
            }
            q = q->fail;
        }
    }
    return ;
}
