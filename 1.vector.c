/*************************************************************************
	> File Name: vector.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年06月04日 星期一 19时27分08秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define malloc2(size) my_malloc()


typedef struct Vector {
    int *data;
    int size, length; //length表示元素个数及最后一个元素下标+1
}Vector;

Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->data = (int *) malloc(n * sizeof(int));
    p->length = 0;
    p->size = n;
    return p;
}

int expand(Vector *v) {
    //第一版
    /*
    int *data = (int *)malloc(sizeof(int) * v->length * 2);
    if (data == NULL) return 0;
    memcpy(data, v->data, sizeof(int) * v->length);
    free(v->data);
    v->data = data;
    */
    //第二版
    int *p = (int *)realloc(v->data, sizeof(int) * (v->size * 2));
    if (p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    printf("vector expand\n");
    return 1;
}

int insert(Vector *v, int x, int ind) {
    if (ind > v->length || ind < 0) {
        return 0;
    }
    if (v->length >= v->size) {
        if (!expand(v)) {
            return 0;
        }
    }
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = x;
    v->length++;
    return 1;
}

int delete_element(Vector *v, int ind){
    if (ind < 0 || ind >= v->length) {
        return 0;
    }
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    return 1;
}

int output(Vector *v) {
    if (v == NULL) return 0;
    for (int i = 0; i < v->length; i++){
        printf("%d ", v->data[i]);
    }
    return 1;
}

void clear(Vector *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
}

int main() {
    srand(time(0));
    Vector *v = NULL;
    v = init(100);
    for (int i = 0; i < 10; i++) {
        int x = rand() % 100, ind = rand() % (i + 1);
        printf("%d : insert(%d, %d)", i, x, ind);
        printf("%d",insert(v, x, ind));
        output(v);
        printf("\n");
    }
    return 0;
}

