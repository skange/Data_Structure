/*************************************************************************
	> File Name: raddix_sort.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年07月28日 星期六 11时49分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define lowbit(x) (x & 0xffff)
#define highbit(x) ((x >> 16) & 0xffff)
void raddix_sort(int *num, int n);

void raddix_sort(int *num, int n) {
    #define MAX_N 65536
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[MAX_N] = {0};
    for (int i = 0; i < n; i++) {
        cnt[lowbit(num[i])]++;
    }
    for (int i = 1; i < MAX_N; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        temp[--cnt[lowbit(num[i])]] = num[i];
    }

    for (int i = 0; i < n; i++) {
        cnt[highbit(temp[i])]++;
    }
    for (int i = 1; i < MAX_N; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        temp[--cnt[highbit(temp[i])]] = num[i];
    }
    free(temp);
}
