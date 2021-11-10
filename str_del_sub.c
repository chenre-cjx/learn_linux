#include <stdio.h>
#include <string.h>
#include <assert.h>

int str_del_sub(char* str1,char* str2);


int main()
{
    char str2[] = {"cd"};
    char str1[] = {"abcdabcda"};
    

    printf("str1 = %p\n",str1);
    printf("str2 = %p\n",str2);

    printf("%s\n",str1);
    str_del_sub(str1,str2);
    printf("str1 : %s\n",str1);

    return 0;
}

int str_del_sub(char* str1,  char* str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    if (strlen(str1) >= strlen(str2))
    {
        int i,j;

        for(i = 0; i <= strlen(str1); i++)
        {
            for(j = 0; j < strlen(str2); j++)
            {
                if (str1[i + j] != str2[j])
                    break;
                else;
            }
        
            if (j == strlen(str2)){                                 //若出现子字符串，则j为子字符串的长度
                printf("----------j = %d,%d\n",j,str2[j]);
                printf("%p,%p\n",str1+i+j,str1+i);
                printf("str1[i] = %c\n",str1[i]);
                
                    for(int n = 0; n<(strlen(str1)-i+1); n++)       //使用位移删除子字符串
                    {
                        str1[i+n] = str1[i+n+j];
                    }
                
                printf("%s\n",str1);
            }
        }
    }else return -1;
}