//header file for adjeceny matrix 

struct AdjMatrixGraph {
	int vertex;
	int edge;
	int **Adj;

};

typedef struct AdjMatrixGraph Graph;

Graph *G; 
//initialize the graph
Graph *init_graph(Graph *G, int v, int e);

//create the graph.
Graph *createGraph(Graph *G, int i, int j);

//Graph Traversal DFS
void DFS(Graph *G, int i);

//BFS
void BFS(Graph *G, int i);

//free Graph
void FreeGraph(Graph *G);

//array to track visited node.
int visited[50];

//array to count indegree of node.
int indgree[50];

