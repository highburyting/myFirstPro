#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include"menu.h"


int Opt(int argc, char * argv[])
{
    const char *optString = "abc";
    opterr = 0;
    int opt;
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'a':
                printf("this -a option\n");
                break;            
            case 'b':
                printf("this -b option\n");
                break;
            case 'c':
                printf("In this cmd, you have 3 option can use:\n");
                printf("-a\n");
                printf("-b\n");
                printf("-c\n");
                break;
            default:
                break;
        }
    }
    // reset global valuable optind
    optind = 0;
    return 0;
}


int Quit(int argc, char * argv[]){
	exit(0);
}


int main(){
	MenuConfig("option","There are 3 options!",Opt);
	MenuConfig("quit","Quit from mymenu!\n",Quit);
	ExecuteMenu();
}
