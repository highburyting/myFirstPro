#include "linktable.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define CMD_MAX_LEN 128

tLinkTable * pLinkTable = NULL;

typedef struct DataNode 
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int(*handler)();
} tDataNode;

int Help();
int Time();
int Pet();
int List();
int Joke();
int Mirror(); 
int Quit();





//菜单初始化

tDataNode * init_tDataNode(char *cmd, char *desc, int(*handler)())
{
	tDataNode *pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = cmd;
    pNode->desc = desc; 
    pNode->handler = handler;
	return pNode;
}

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();

    tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));
	
    pNode = init_tDataNode("help", "This is help cmd!", Help);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = init_tDataNode("version", "Menu v3.0", NULL);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode); 

    pNode = init_tDataNode("time","Show the time!",Time);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = init_tDataNode("pet","Free pet!",Pet);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = init_tDataNode("ls","List the current directory!",List);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = init_tDataNode("joke","Jokes!",Joke);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = init_tDataNode("mirror","There is a mirror!", Mirror);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = init_tDataNode("quit","Quit from Menu!",Quit);
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    return 0;
}






//菜单命令的函数实现

tDataNode * FindCmd(tLinkTable linkTable, char * cmd)
{
    tDataNode * pNode = (tDataNode *)GetLinkTableHead(linkTable);
    while (pNode != NULL)
    {
        if (strcmp(pNode->cmd, cmd) == 0)
        {
            return pNode;
        }
        pNode = (tDataNode *)GetNextLinkTableNode(linkTable, (tLinkTableNode *)pNode);
    }
    return NULL;
}


int ShowAllCmd(tLinkTable LinkTable)
{
    tDataNode * pNode = (tDataNode *)GetLinkTableHead(LinkTable);
    while (pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode *)GetNextLinkTableNode(LinkTable, (tLinkTableNode *)pNode);
    }
    return 0;
}


int Help()
{
    ShowAllCmd(*pLinkTable);
    return 0;
}


int Time()
{
    time_t timep;
    time(&timep);
    printf("%s\n",asctime(gmtime(&timep)));
    return 0;
}

int Pet()
{
    printf(" ┏┓　 　┏┓\n┏┛┻━━━━━┛┻┓\n┃　　　 　┃  \n┃　┳┛  ┗┳ ┃ \n┃　　　　 ┃\n");
    printf("┃　　┻　  ┃\n┗━┓　　 ┏━┛\n　┃　　 ┃\n　┃　 　┗━━━┓\n　┃　　　 　┣┓\n");
    printf("　┃　    　┏┛\n　┗┓┓┏━━┳┓┏┛\n　 ┃┫┫  ┃┫┫\n　 ┗┻┛  ┗┻┛\n");
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

int Quit()
{
    exit(0);
}





//主函数

int main()
{
    InitMenuData(&pLinkTable);
	while (1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Please input your cmd : \n");
		scanf("%s", cmd);
        tDataNode * p = FindCmd(*pLinkTable, cmd);
        if (p == NULL)
        {
            printf("Invalid cmd!\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if (p->handler != NULL)
        {
            p->handler();
        }
	}
    return 0;
}
