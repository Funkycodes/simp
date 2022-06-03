#include "shell.h"
void unset_env(list_t **h,char *var)
{
    int idx;
    idx = get_node(*h,var);
    delete_nodeint_at_index(h,idx);
}
void set_env(list_t **h,char *var,char *val)
{
    int idx;
    list_t *node = *h;
    char *nodevar;
    nodevar = _strcat(var,"=");
    nodevar = _strcat(nodevar,val);
    idx = get_node(*h,nodevar);
    if(idx == -1)
    {
        add_node_end(h,nodevar);
    }else
    {
        int i =0;
        while(i < idx)
        {
            if(_strcmp(node->var,nodevar))
            {
                node -> var = nodevar;
                return;
            }
            node = node -> next;
            i++;
        }
    }
}
