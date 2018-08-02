/*************************************************************************
	> File Name: three_point_search.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年07月28日 星期六 15时01分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int f(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
}

double three_point_search(int a, int b, int c) {
    #define EPS 1e-6
    double head = -10000, tail = 10000, m1, m2;
    while (fabs(tail - head) > EPS) {
        m1 = (tail - head) / 3 + head;
        m2 = (tail - head) / 3 * 2 + head;
        if (f(m1, a, b, c) > f(m2, a, b, c)) {
            head = m1;
        } else {
            tail = m2;
        }
    }
    return head;
    #undef EPS
}

int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return -1;
}

//11111000000
int binary_search2(int *num, int n, int x) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] <= x) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;
}

//000000111111
int binary_search3(int *num, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] >= x) {
            tail = mid;
        } else {
            head = mid + 1;
        }
    }
    return head == n ? -1 : head;
}

int main() {
    srand(time(0));
    int size = rand() % 1000 + 10;
    int *num = (int *)malloc(sizeof(int ) * size);
    num[0] = 0;
    for (int i = 1; i < size; i++) {
        num[i] = rand() % 2 + num[i - 1];
    }
    int key = rand() % (num[size - 1] + 10);
    printf("num[%d] = [", size);
    for (int i = 0; i < size; i++) {
        printf("%d, ", num[i]);
    }
    printf("]\n");
    
    int index = binary_search3(num, size, key);
    printf("binary_search3 : key = %d, index = %d\n", key, index);
    if (index >= 0) {
        printf("num[%d] = %d", index, num[index]);
    } else {
        printf("not found!\n");
    }
    return 0;
}
