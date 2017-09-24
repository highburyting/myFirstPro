#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DataNode
{
    char*    cmd;
    char*    desc;
    int      (*handler)();
    struct   DataNode *next;
} tDataNode;



int Quit()
{
    exit(0);
    return 0;
}

int Sing()
{
    printf("Guaguagua~~Guagua~~\n");
    return 0;
}

int Cry()
{
    printf("Wuwuwu~~\n");
    return 0;
}
int Joke()
{
    printf("There are two jokes! Which one do you want?\n");
    while(1)
    {
        printf("Please input 1 or 2:\n");
        int num = 0;
        scanf("%d", &num);
        if (num == 1)
        {
            printf("Haha! There is no jock at all!\n");
            break;
        }
        else if(num == 2)
        {
            printf("Haha! There is only one jock!\n");
            break;
        }
        else
        {
            printf("There is no such jock!\n");
        };
     }
     return 0;
}

int Pet()
{
    printf(" ┏┓　 　┏┓\n┏┛┻━━━━━┛┻┓\n┃　　　 　┃  \n┃　┳┛  ┗┳ ┃ \n┃　　　　 ┃\n");
    printf("┃　　┻　  ┃\n┗━┓　　 ┏━┛\n　┃　　 ┃\n　┃　 　┗━━━┓\n　┃　　　 　┣┓\n");
    printf("　┃　    　┏┛\n　┗┓┓┏━━┳┓┏┛\n　 ┃┫┫  ┃┫┫\n　 ┗┻┛  ┗┻┛\n");
    return 0;
}
   

int Mirror()
{
    char sex[5];
    printf("Are you a girl or a boy?\n");
    scanf("%s", sex);
    if(strcmp(sex, "girl") == 0)
    {
        printf("You are the most beautiful girl in the world!\n");
    }
    else if(strcmp(sex, "boy")==0)
    {
        printf("You are the most handsome boy in the world!\n");
    }
    else
    {
        printf("The mirror said nothing!\n");
    }
}

int Help();
int Add();

static tDataNode head[] =
{
    {"help", "This is help cmd!", Help, &head[1]},
    {"version", "Menu v1.0", NULL, &head[2]},
    {"sing", "Sing a song!", Sing, &head[3]},
    {"pet", "Free pet!", Pet, &head[4]},
    {"cry", "It sounds like crying!", Cry, &head[5]},
    {"joke", "Jokes!", Joke, &head[6]},
    {"mirror", "There is a mirror!", Mirror, &head[7]},
    {"quit", "Quit from Menu!", Quit, NULL}
};


int Add()
{
    tDataNode *p = head, *q;
    while(p != NULL)
    {
        q = p;
        p = p->next;
    }
    p = (tDataNode *)malloc(sizeof(tDataNode));
    p->handler = NULL;
    scanf("%s%s", p->cmd, p->desc);
    q->next = p;
    p->next = NULL;
    return 0;
}


int Help()
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}

int main()
{
    char cmd[128];
    while(1)
    {
        printf("Please input your cmd:\n");
        scanf("%s",cmd);
        tDataNode *p = head;
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

