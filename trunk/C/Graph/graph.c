
//Initialize the graph
Graph *init_graph(Graph *G, int v, int e) {
	int i=0,j=0;
	G = (Graph *)malloc(sizeof(Graph));
	if(!G) {
		printf("Memory Error\n ");
		return NULL;
	}
	G->vertex = v;
	G->edge = e;
	G->Adj = (int **)malloc(sizeof(int)*v*v);
	if(!G->Adj) {
		printf("Memory Error\n");
		return NULL;
	}	
	for(;i<v;i++) {
		G->Adj[i] = (int *)malloc(sizeof(int)*v);
		if(!G->Adj[i]) {
			printf("Memeory Error\n");
			return NULL;
		}
	}
	for(i<v;i++) {
		for(;j<v;j++) {
			G->Adj[i][j] = 0;	
		}
	}	
	
	return G;
}

//create Graph
Graph *createGraph(Graph *G, int i, int j) {
	if(G)
		G->Adj[i][j] = 1;
}

//DFS Traversal of a Graph.
//before using visited array initialize with 0;
void DFS(Graph *G, int i) {
	int j=0;
	if(!G) {
		printf("Graph is Empty\n");
		return 0;
	}
	visited[i] = 1;
	for(;j<G->vertex;j++) {
		if(!visited[j] && G->Adj[i][j])
			DFS(G,j);
	}
}

