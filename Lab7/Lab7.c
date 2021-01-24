/* 
 * This program implements C string functions (from string.h library) from scratch
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void psqueeze(char *s, int c);
void pstr_cat(char *s, char *t);
void pstr_ncpy(char *dest, char *src, int n);
int str_len(char *s);
int pstr_ncmp(char *s, char *t, int n);
void cswap(char *c, char *d);
void preverse(char *s);
char *pindex(char *s, int c);

/* same as strlen */
int str_len(char *s)
{
    int i = 0;
    while (*(s+i) != '\0') {
        i++;
    }

    return i;
}

/* same as str_ncpy */
void pstr_ncpy(char *dest, char *src, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        *(dest+i) = *(src+i);
    }    
}

/* same as str_cat */
void pstr_cat(char *s, char *t)
{   
    int len = str_len(s);
    int end = str_len(t);
    int i = 0;
    for (i = 0; i < end; i++) {
        *(s + len + i) = *(t + i);
    }
}

/* same as str_ncmp */
int pstr_ncmp(char *s, char *t, int n)
{
    int i;
    int count1 = 0;
    int count2 = 0;
    for (i = 0; i < n; i++) {
        count1 += (int) *(s + i);
        count2 += (int) *(t + i);
    }

    int diff = (count1 - count2) / abs(count1 - count2);
    return diff;
}

/* same as index */
char *pindex(char *s, int c)
{
    int i;
    char *p;
    for (i = 0; *(s+i) != '\0'; i++) {
        if (*(s+i) == c) {
            p = s+i;
            return p;
        }
    }

    return NULL;
}

/* removes character c from string s */
void psqueeze(char *s, int c)
{
    int i, j;
    for (i = 0, j = 0; *(s+i) != '\0'; i++, j++) {
        *(s+i) = *(s+j);
        if (*(s+i) == c) {
            i--;
        }
    }
}

/* swaps two characters */
void cswap(char *c, char *d)
{
    char tmp = *c;
    *c = *d;
    *d = tmp;
}

/* reverses string s */
void preverse(char *s)
{
    int i;
    char *a;
    char *b;
    int len = str_len(s);
    for (i = 0; i < len/2; i++) {
        a = s+i;
        b = s+(len-1)-i;
        cswap(a, b);
    }
}

int main(void)
{
    char *str = "Brendan";

    /* test str_len function */
    int len = str_len(str);
    printf("%d\n", len);
    assert(len == 7);

    /* test copy function */
    char s[100];
    pstr_ncpy(s, str, len);
    printf("%s\n", s);
    //assert(s == str);

    /* test concatenate function */
    char s1[100]; 
    char *s2 = " Noone";
    pstr_ncpy(s1, str, str_len(str));
    pstr_cat(s1, s2);
    printf("%s\n", s1);

    /* test string compare function */
    char *s3 = "brendan noone";
    int res = pstr_ncmp(s1, s3, 7);
    printf("%d\n", res);
    assert(res == -1);

    /* test index function */
    char *index;
    index = pindex(str, 'e');
    printf("%c\n", *index);

    /* test squeeze function */
    psqueeze(s1, 'o');
    printf("%s\n", s1);

    /* test character swap function */
    char a = 'B';
    char b = 'N';
    printf("%c, %c\n", a, b);
    cswap(&a, &b);
    printf("%c, %c\n", a, b);

    /* test reverse function */
    preverse(str);
    printf("%s\n", str);

    return 0;
}