#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue.h"
#include "tree.h"

void subtree_node_print(int x);
void path_to_root_print(int x);
void relation_print(int x, int y);

int main()
{

    tree_generate();
    printf("\n");
    print_tree();
    while(1)
    {
        printf("?\n");
        char input_string[15];
        char name1[15], name2[15];
        int x, y;
        scanf("%s",input_string);
        if(!strcmp(input_string,"END"))
        {
            printf("program end\n");
            return 0;
        }
        if(input_string[0]=='A')
        {
            sscanf(input_string,"A(%[^')'])",name1);
            x=name_to_index(name1);
            subtree_node_print(x);
        }else if(input_string[0]=='D')
        {
            sscanf(input_string,"D(%[^')'])",name1);
            x=name_to_index(name1);
            path_to_root_print(x);
        }else if(input_string[0]=='R')
        {
            sscanf(input_string,"R(%[^’,’],%[^’)’])",name1,name2);
            x=name_to_index(name1);
            y=name_to_index(name2);
            relation_print(x,y);
        }
    }
}

void subtree_node_print(int x)
{
    printf("A(%s) = ",tree[x]);
    if(find_dad(x)==-1&&find_mom(x)==-1)
    {
        printf("Unknown\n");
        return;
    }
    addq(find_mom(x));
    addq(find_dad(x));
    while(front)
    {
        int tmp = deleteq();
        print_name(tmp);
        printf(", ");
        if(find_mom(tmp)!=-1)
            addq(find_mom(tmp));
        if(find_dad(tmp)!=-1)
            addq(find_dad(tmp));
    }
    printf("\n");
}

void path_to_root_print(int x)
{
    printf("D(%s) = ",tree[x]);
    if(find_child(x)==-1)
    {
        printf("Unknown\n");
        return;
    }

    for(int tmp = find_child(x);tmp!=-1;tmp=find_child(tmp))
    {
        print_name(tmp);
        printf(", ");
    }
    printf("\n");
}
void relation_print(int x, int y)
{
    printf("R(%s,%s) = ",tree[x],tree[y]);
    int a = find_depths(y) - find_depths(x);
    int cur_node = x;
    printf("%s -> ",tree[x]);
    for(int i=a-1; i>=0;i--)
    {
        int tmp = y;
       //tmp/=pow(2,i);
        tmp = tmp>>i;
        int relation_num = tmp%2;
        if(relation_num == 0)
        {
            printf("M -> ");
            print_name(find_mom(cur_node));
            cur_node = find_mom(cur_node);
        }
        if(relation_num == 1)
        {
            printf("F -> ");
            print_name(find_dad(cur_node));
            cur_node = find_dad(cur_node);
        }
        if(y!=cur_node)
        {
            printf("-> ");
        }
    }
    printf("\n");
}