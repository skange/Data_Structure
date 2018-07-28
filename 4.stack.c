/*************************************************************************
	> File Name: 4.stack.cpp
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年07月19日 星期四 11时46分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define data_type int
#define NULL_VALUE 0

typedef struct Stack {
    data_type *data;
    int top, size;
} Stack;

Stack *init(int n);
void clear(Stack *);
data_type top(Stack *);
int push(Stack *, data_type);
int pop(Stack *);
int empty(Stack *);
void output_arrow(Stack *);


int main() {
    srand(time(0));
    Stack *s = init(5);
    for (int i = 0; i < 20; i++) {
        int op = rand() % 2, value = rand() % 100;
        switch (op) {
            case 0: 
                printf("pop element from stack = %d\n", pop(s));
                output_arrow(s);
                break;
            case 1:
                printf("insert %d to stack\n", value);
            if (push(s, value)) {
                output_arrow(s);
            }
                
        } 
    } 
}

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (data_type *)malloc(sizeof(data_type));
    s->top = -1;
    s->size = n;
    return s;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
}

data_type top(Stack *s) {
    if (empty(s)) {
        return 0;
    }
    return s->data[s->top];
}

int push(Stack *s, data_type value) {
    if (s->top + 1 == s->size) {
        return 0;
    }
    s->data[++s->top] = value;
    return 1;
}

int pop(Stack *s) {
    if (empty(s)) {
        return 0;
    }
    --s->top;
    return 1;
}

int empty(Stack *s) {
    return s->top == -1;
}

void output_arrow(Stack *s) {
    int charnum = 0;
    printf("[");
    for (int i = 0; i < s->size; i++) {
        if (i <= s->top) {
            printf("%d", s->data[i]);
            charnum += (int)log10(s->data[i]) + 2;
        }
        if (i != s->size - 1)
        printf(",");
    }
    printf("]\n");
    charnum--;
    for (int i = 0; i < charnum; i++) {
        printf(" ");
    }
    printf("^\n");
    for (int i = 0; i < charnum; i++) {
        printf(" ");
    }
    printf("|\n");
    charnum -= charnum > 0;
    for (int i = 0; i < charnum; i++) {
        printf(" ");
    }
    printf("top\n");
}
