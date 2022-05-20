#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void tree_generate()
{   
    char** dy_tree = (char**)malloc(sizeof(char*)*NUM_NODE);
    for(int i =0; i<NUM_NODE;i++)
        dy_tree[i] = (char*)malloc(sizeof(char)*10);
    char tree_name[NUM_NODE][10] = {"HyunWook","So","Beom","Na","MuIk","SunIm","Heong","DdoRong","NamJu","Chae","BuJin","SunBok","Hong","SunIe","GoChang"};
    for(int i=1; i<=NUM_NODE;i++)
    {
        strcpy(dy_tree[i-1],tree_name[i-1]);
        tree[i] = dy_tree[i-1];
    }
}

void print_tree()
{
    for(int h=0; h<4;h++)
    {
        for(int i = pow(2,h); i<pow(2,h+1);i++)
        {
            printf("%s  ",tree[i]);
        }
        printf("\n");

    }
}
int find_child(int i)
{
    if(i>1)
        return i/2;
    return -1;
}
int find_mom(int i)
{
    if(i*2<16)
        return i*2;
    return -1;
}
int find_dad(int i)
{
    if(i*2+1<16)
    {
        return i*2+1;
    }
    return -1;
}
char* print_name(int i)
{
    printf("%s ",tree[i]);
    return tree[i];
}
int name_to_index(char* name)
{
    for(int i=1; i<=NUM_NODE;i++)
    {
        if(!strcmp(name,tree[i]))
        {
            return i;
        }
    }
    return -1;
}
int find_depths(int i)
{
    for(int j=0; j<4;j++)
    {
        if(i<pow(2,j+1))
            return j;
    }
    return -1;
}

