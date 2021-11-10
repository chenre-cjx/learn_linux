#include <stdio.h>
#include <string.h>
#include <assert.h>


int str_cat(char* str1,const char* str2);

int main()
{
    char str1[] = {"abcdefg"};
    char str2[] = {"hijklmn"};
    str_cat(str1, str2);
    printf("%s\n",str1);

    return 0;
}

int str_cat(char* str1,const char* str2)
{
    int i,j,k;  //循环指针

    assert(str1 != NULL);
    assert(str2 != NULL);

    char *p = str1;
    for(i = 0;str1[i] != '\0'; i++);
    for(j = 0;str2[j] != '\0' ; j++);

    printf("%d\n",str1[i]);
    printf("%d\n",str1[j]);

    for(k = 0;k <= j; k++){
        p[i++] = str2[k];
        printf("%c\n",str2[k]);
    }

    return 0;
}