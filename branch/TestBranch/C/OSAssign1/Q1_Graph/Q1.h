
//node that adjecency list contain
struct node {
	int vertex_no;
	struct node *next;

};
 typedef  struct node list_node ;

//global list_node varible
//list_node *node;

//head node of a graph
struct Adj_graph {
	int V;
	int E;
	struct node **Adj;
};
 typedef struct Adj_graph graph;

//global graph variable
graph *G;


//initilization of a graph
int init_graph(int V);

//create a undirected graph
int create_graph(int v1, int v2);

//DFS traversal of graph
void DFS(graph *g,int i);

//DFS traversal for cycle detection.
int isCycle(graph *g,int startVrtx,int endVrtx);

int visited[50];
int back_edge[50];
int length;
int cycle_flag;
