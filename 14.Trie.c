/*************************************************************************
	> File Name: 14.Trie.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年08月04日 星期六 15时29分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define BASE 26
#define BEGIN_LETTER 'a'


typedef struct Node {
    int flag;
    struct Node *next[BASE];
} Node, *Trie;

Node *get_new_node();
void clear(Trie);
Node *insert(Trie, const char *);
int search(Trie, const char *);
void get_random_string(char *);
void output(Trie, char *, int);

int node_cot;

int main() {
    srand(time(0));
    #define INSERT_CNT 20
    Trie root = NULL;
    char str[100];
    int word_cot = 0;
    for (int i = 0; i < INSERT_CNT; i++) {
        get_random_string(str);
        root = insert(root, str);
        word_cot += strlen(str);
        printf("insert %s to Trie\n", str);
    }
    output(root, str, 0);
    printf("storage rate : %lf\n", 1.0 * word_cot / (1.0 * node_cot * sizeof(Node)));
    #undef INSERT_CNT
    return 0;
}


Node *get_new_node() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->flag = 0;
    memset(p->next, 0, sizeof(Node *) * BASE);
    node_cot++;
    return p;
}

void clear(Trie root) {
    if (root == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(root->next[i]);
    }
    free(root);
    return ;
}

Node *insert(Trie root, const char *str) {
    if (root == NULL) {
        root = get_new_node();
    }
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - BEGIN_LETTER;
        if (p->next[str[i] - BEGIN_LETTER] == NULL) {
            p->next[ind] = get_new_node();
        }
        p = p->next[ind];
    }
    p->flag = 1;
    return root;
}

int search(Trie root, const char *str) {
    Node *p = root;
    int i = 0;
    while (p) {
        int ind = str[i++] - BEGIN_LETTER;
        p = p->next[ind];
    }
    return p && p->flag == 1;
}

void get_random_string(char *str) {
    int len = rand() % 10 + 1;
    for (int i = 0; i < len; i++) {
        str[i] = BEGIN_LETTER + rand() % BASE;
    }
    str[len] = 0;
    return ;
}

void output(Trie root, char *str, int level) {
    if (root == NULL) return ;
    str[level] = 0;
    if (root->flag) {
        printf("find word : %s\n", str);
    }
    for (int i = 0; i < BASE; i++) {
        if (root->next[i] == NULL) continue;
        str[level] = i + BEGIN_LETTER;
        output(root->next[i], str, level + 1);
    }
    return ;
}
