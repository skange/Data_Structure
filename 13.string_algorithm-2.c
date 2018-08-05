/*************************************************************************
	> File Name: 13.string_algorithm-2.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年08月04日 星期六 11时54分45秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define TEST(func ) {\
    printf("%s = %d\n", #func, func);\
}

int sunday(const char *text, const char *pattern) {
    #define MAX_SIZE 127
    int len = strlen(pattern), len2 = strlen(text);
    int ind[MAX_SIZE] = {0};
    for (int i = 0; i < MAX_SIZE; i++) {
        ind[i] = len + 1;
    } 
    for (int i = 0; pattern[i]; i++) {
        ind[pattern[i]] = len - i;
    }
    for (int i = 0; i < len2 - len; ) {
        int j = 0; 
        for (; j < len; j++) {
            if (pattern[j] != text[i + j]) break;
        }
        if (j == len) return 1;
        i += ind[text[i + len]];
    }
    return 0;
}

int shift_and(const char *text, const char *pattern) {
    int d[MAX_SIZE] = {0}, n = 0;
    for (; pattern[n]; n++) {
        d[pattern[n]] |= (1 << n);
    }
    int p = 0;
    for (int i = 0; text[i]; i++) {
        p = (p << 1 | 1) & d[text[i]];
        if (p & (1 << (n - 1))) return 1;
    }
    return 0;
}

int main() {
    TEST(sunday("hello world", "hello"));
    TEST(sunday("hello world", "helo"));
    TEST(sunday("hello world", "he"));
    TEST(shift_and("hello world", "hello"));
    TEST(shift_and("hello world", "helo"));
    TEST(shift_and("hello world", "he"));
    return 0;
}
