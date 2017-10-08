typedef struct DataNode
{
    char*    cmd;
    char*    desc;
    int      (*handler)();
    struct   DataNode *next;
}tDNode;

