/*************************************************************************
	> File Name: 7.heap.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年07月23日 星期一 17时20分20秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Heap {
    int *data;
    int index, size;
} Heap;

Heap *init(int);
void clear(Heap *);
void push(Heap *, int);
void pop(Heap *);
void output(Heap *);

int main() {
    srand(time(0));
    Heap *p = init(21);
    for (int i = 0; i < 20; i++) {
        int value = rand() % 100;
        printf("insert %d to heap\n", value);
        push(p, value);
        output(p);
    }
    for (int i = 0; i < 20; i++) {
        pop(p);
        output(p);
    }
    clear(p);
    return 0;
}

Heap *init(int size) {
    Heap *p = (Heap *)malloc(sizeof(Heap));
    p->data = (int *)calloc(size, sizeof(int));
    p->size = size;
    p->index = 0;
    return p;
}

void clear(Heap *h) {
    if (h == NULL) {
        return ;
    }
    free(h->data);
    free(h);
    return ;
}

void push(Heap *h, int value) {
    if (h->index == h->size) return ;
    h->index += 1;
    h->data[h->index] = value;
    for (int i = h->index; i > 1; i >>= 1) {
        if (h->data[i] <= h->data[i >> 1]) break;
        h->data[i] ^= h->data[i >> 1] ^= h->data[i] ^= h->data[i >> 1];
    }
    return ;
}

void pop(Heap *h) {
    if (h->index <= 1) {
        h->index = 0; 
        return ;
    }
    h->data[1] ^= h->data[h->index] ^= h->data[1] ^= h->data[h->index];
    h->index -= 1;
    int ind = 1;
    while (ind * 2 <= h->index) {
        int swap_ind = ind;
        if (h->data[ind << 1] > h->data[swap_ind]) 
            swap_ind = ind << 1;
        if ((ind << 1 | 1) <= h->index && h->data[ind << 1 | 1] > h->data[swap_ind])
            swap_ind = ind << 1 | 1;
        if (swap_ind == ind) break;
        h->data[ind] ^= h->data[swap_ind];
        h->data[swap_ind] ^= h->data[ind];
        h->data[ind] ^= h->data[swap_ind];
        ind = swap_ind;
    }
    return ;
}

void output(Heap *h) {
    printf("heap = [");
    for (int i = 0; i < h->size; i++) {
        printf("%d, ", h->data[i]);
    }
    printf("]\n");
    return ;
}
