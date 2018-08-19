/*************************************************************************
	> File Name: 18.UnionSet.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年08月11日 星期六 11时29分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct UnionSet {
    int *data, size;
    itn n;
    int cnt;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *p = (UnionSet *)malloc(sizeof(UnionSet));
    p->data = (int *)malloc(sizeof(int ) * n);
    p->n = p->cnt = n;
    for (int i = 0; i < n; i++) {
        p->data[i] = i;
    }
    return p;
}

void clear(UnionSet *u) {
    if (u == NULL) return;
    free(u->data);
    free(u->size);
    free(u);
    return ;
}

int find(UnionSet *u, int n) {
    if (u->data[n] == n) return n;
    int father = find(u, u->data[n]);
    u->data[n] = father;
    return father;
}

int merge(UnionSet *u, int a, int b) {
    int father_a = find(u, a), father_b = find(u, b);
    if (father_a == father_b) return 0;
    if (u->size[father_a] > u->size[father_b]) {
        u->data[father_b] = father_a;
        u->

    }
}

int main() {
    return 0;
}
