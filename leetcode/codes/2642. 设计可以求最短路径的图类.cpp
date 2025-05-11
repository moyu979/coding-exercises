class Graph {
public:
    int D[102][102];
    int n;
    int dis=-1;
    Graph(int n, vector<vector<int>>& edges) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                D[i][j]=dis;
            }
        }
        for(auto edge:edges){
            D[edge[0]][edge[1]]=edge[2];
        }
        this->n=n;
        for(int i=0;i<n;i++){
            D[i][i]=0;
        }
        
        for(int k=0;k<=n;k++){
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(D[i][k]>=0 && D[k][j]>=0){
                        if(D[i][j]<0 || D[i][j]>D[i][k]+D[k][j])
                            D[i][j]=D[i][k]+D[k][j];
                    }
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int from=edge[0];
        int to=edge[1];
        int cost=edge[2];
        if(cost>D[from][to] && D[from][to]>0){
            return;
        }
        D[from][to]=cost;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][from]>=0 && D[to][j]>=0)
                    if(D[i][j]<0 || D[i][j]>D[i][from]+cost+D[to][j]){
                    D[i][j]=D[i][from]+cost+D[to][j];
                    }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return D[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */