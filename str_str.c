#include <stdio.h>
#include <string.h>
#include <assert.h>

int str_str(char* str1,char* str2, char** sub);


int main()
{
    char str2[] = {"cd"};
    char str1[] = {"abcdefg"};
    
    char *sub ='\0';
    printf("str1 = %p\n",str1);
    printf("str2 = %p\n",str2);
    printf("sub = %p\n",&sub);

    str_str(str1,str2,&sub);
    printf("%p\n",sub);

    return 0;
}

int str_str(char* str1,  char* str2, char** sub)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    int i,j;

    for(i = 0; i < (strlen(str1) - strlen(str2)); i++)
    {
        for(j = 0; j < strlen(str2); j++)
        {
            if (str1[i + j] != str2[j])
                break;
            else;
        }
        if (j == strlen(str2)){
            printf("%p\n,%c\n",str1+i,*(str1+i));
            (*sub) = str1 + i;
            printf("%p\n",*sub);
        }
    }
}