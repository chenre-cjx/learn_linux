#include <stdio.h>
#include <string.h>
#include <assert.h>

int str_cmp(const char *str1, const char *str2);

int main()
{
    char str1[] = {"abcdefg"};
    char str2[] = {"abcdefg"};

    if (str_cmp(str1,str2)){
        printf("==\n");
    }else printf("!=\n");


    return 0;
}

int str_cmp(const char *str1, const char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    for(int i = 0; (str1[i] != '\0') || (str2[i] != '\0'); i++)
    {
        if (str1[i] != str2[i])
        return 0;
    }
    return 1;

}