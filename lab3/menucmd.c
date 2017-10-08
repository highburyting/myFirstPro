#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "datanode.h"


int Quit()
{
    exit(0);
    return 0;
}

int Time()
{
    time_t timep;
    time(&timep);
    printf("%s\n",asctime(gmtime(&timep)));
    return 0;
}

int List()
{
    system("ls");
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



tDNode head[] =
{
    {"help", "This is help cmd!", Help, &head[1]},
    {"version", "Menu v1.0", NULL, &head[2]},
    {"time", "Show the time!", Time, &head[3]},
    {"pet", "Free pet!", Pet, &head[4]},
    {"ls", "List the current directory!", List, &head[5]},
    {"joke", "Jokes!", Joke, &head[6]},
    {"mirror", "There is a mirror!", Mirror, &head[7]},
    {"quit", "Quit from Menu!", Quit, NULL}
};


int Help()
{
    printf("Menu List:\n");
    tDNode *p = head;
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}

