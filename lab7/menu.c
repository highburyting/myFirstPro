/********************************************************************/
/* Copyright (C) SSE-USTC, 2017-2018                                */
/*                                                                  */
/*  FILE NAME             :  menu.c                                 */
/*  PRINCIPAL AUTHOR      :  WangTao                                */
/*  SUBSYSTEM NAME        :  menu                                   */
/*  MODULE NAME           :  menu                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2017/11/06                             */
/*  DESCRIPTION           :  menu                                   */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by WangTao, 2017/11/06
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_MAX_ARGV_NUM 128
tLinkTable * head = NULL;
/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)(int argc, char * argv[]);
} tDataNode;


int SearchCondition(tLinkTableNode * pLinkTableNode, void * args)
{
    char * cmd = (char *)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}


tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,(void *)cmd);
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int Help(int argc, char * argv[]){
    ShowAllCmd(head);
}

int AddNewCommand(char * cmd, char * desc, int(* handler)(int argc, char * argv[])){
	tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));
	pNode->cmd = cmd;
	pNode->desc = desc;
	pNode->handler = handler;
	AddLinkTableNode(head, (tLinkTableNode *)pNode);
}

int MenuConfig(char * cmd, char * desc, int (* handler)(int argc, char * argv[])){
	if( head == NULL){
		head = CreateLinkTable();
		AddNewCommand("help", "Menu List:", Help);
	}
	AddNewCommand(cmd, desc, handler);
	return 0;
}

/*将输入的命令与参数分离*/
int splitcommand(char * pcmd, char * argv[]){
        int argc = 0;
        pcmd = strtok(pcmd," ");
        while(pcmd != NULL&& argc < CMD_MAX_ARGV_NUM){
            argv[argc] = pcmd;
            argc++;
            pcmd = strtok(NULL," ");
        }
        if(argc == 1){
            int len = strlen(argv[0]);
            *(argv[0] + len - 1) = '\0';
        }
        return argc;
}

int ExecuteMenu(){ 
   /* cmd line begins */
    while(1)
    {   
        int argc = 0;
        char * argv[CMD_MAX_ARGV_NUM];
        char * pcmd = NULL;
        char cmd[CMD_MAX_LEN];

        printf("Please input your command > ");
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        if(pcmd == NULL){
        	continue;
        }

        argc = splitcommand(pcmd, argv);
        
        tDataNode *p = FindCmd(head, argv[0]);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler(argc, argv);
        }
   
    }
    return 0;
}
