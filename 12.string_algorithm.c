/*************************************************************************
	> File Name: 12.string_algorithm.c
	> Author: ShangKe
	> Mail: 
	> Created Time: 2018年08月02日 星期四 20时35分45秒
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int BF(const char *text, const char *pattern);
int KMP(const char *text, const char *pattern);


int main() {
    char str1[] = "hello world";
    printf("BF(%s, %s) = %d\n", str1, "wor", BF(str1, "wor"));
    printf("KMP(%s, %s) = %d\n", str1, "wor", KMP(str1, "wor"));
    return 0;
}


int BF(const char *text, const char *pattern) {
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    for (int i = 0; i < len1 - len2 + 1; i++) {
        int flag = 1;
        for (int j = 0; pattern[j] && flag; j++) {
            if (text[i + j] == pattern[j]) continue;
            flag = 0;
        }
        if (flag) return 1;
    }
    return 0; 
}
int KMP(const char *text, const char *pattern) {
    #define RETURN(a) { \
        free(next); \
        return a; \
    }
    int len1 = strlen(text);
    int len2 = strlen(pattern);
    int *next = (int *)malloc(sizeof(int) * len2);
    int j = -1;
    next[0] = -1;
    for (int i = 1; i < len2; i++) {
        while (j != -1 && pattern[j + 1] != pattern[i]) j = next[j];
        if (pattern[j + 1] == pattern[i]) {
            j += 1;
        }
        next[i] = j;
    }
    j = -1;
    for (int i = 0; text[i]; i++) {
        while (j != -1 && pattern[j + 1] != text[i]) j = next[j];
        if (pattern[j + 1] == text[i]) j += 1;
        if (pattern[j + 1] == 0) RETURN(1);
    }
    RETURN(0);
    #undef RETURN
}
