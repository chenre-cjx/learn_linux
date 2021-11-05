#include "sys/types.h"
#include "unistd.h"
#include "stdio.h"

int main(int avr,char * argv[])
{
    int i = 0;
    for (i = 0; i < avr; i++){
        printf("arc[%d] ------> %s \n", i,argv[i]);
    }
    return 0;
}