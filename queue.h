typedef struct q_node* nodeptr;
typedef struct q_node
{
    int data;
    nodeptr link;
};

void addq(int item);
int deleteq();
void printq();

nodeptr front, rear;
