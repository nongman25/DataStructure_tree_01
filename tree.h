#define NUM_NODE 15

char* tree[NUM_NODE+1];

void tree_generate();
void print_tree();
int find_child(int);
int find_mom(int);
int find_dad(int);
char* print_name(int);
int name_to_index(char*);
int find_depths(int);
