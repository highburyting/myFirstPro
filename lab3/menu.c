#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datanode.h"

extern tDNode head[];
int main()
{
    char cmd[64];
    while(1)
    {
        printf("Please input your cmd:\n");
        scanf("%s",cmd);
        tDNode *p = head;
        while(p != NULL)
        {        
            if(strcmp(p->cmd,cmd) == 0)
            {
                printf("%s    %s\n", p->cmd, p->desc);
                if(p->handler != NULL)
                {
                    p->handler();
                }
                break;
            }
            p = p->next; 
        }
        if(p == NULL)
        {
            printf("Invalid command!\n");
        }
    }
    return 0;
}

