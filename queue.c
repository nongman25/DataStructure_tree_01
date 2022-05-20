#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void addq(int i)
{
    nodeptr tmp;
    tmp = (nodeptr)malloc(sizeof(*tmp));
    tmp->data = i;
    tmp->link = NULL;
    if(front)
        rear->link=tmp;
    else
    {
        front = tmp;
    }
    rear = tmp;
}

int deleteq()
{
    nodeptr tmp = front;
    int d = tmp->data;
    if(!front)
    {
        printf("queue is empty\n");
        return -1;
    }
    front = tmp->link;
    free(tmp);
    return d;
}

void printq()
{
    nodeptr tmp;
    for(tmp = front; tmp!= NULL; tmp=tmp->link)
    {
        printf("%d -> ",tmp->data);
    }
    printf("\n");
}