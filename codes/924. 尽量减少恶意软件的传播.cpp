class Solution {
public:
    int n;
    vector<int> *state;
    vector<int> number;
    vector<vector<int>> neighbours;
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n=graph.size();
        sort(initial.begin(),initial.end());
        state=new vector<int>(n);
        for(int i:initial){
            (*state)[i]=-1;
        }
        int visited=initial.size();
        for(int i=0;i<n;i++){
            if((*state)[i]!=1){
                dfs(i,graph);
            }
        }

        int rm_max=-1;
        int node=-1;
        for(int i:initial){
            int del=0;
            for(int j=0;j<neighbours.size();j++){
                if(neighbours[j].size()==1 && neighbours[j][0]==i){
                    del+=number[j];
                }
            }
            if (del>rm_max){
                rm_max=del;
                node=i;
            }  
        }
        return node;
    }
    void dfs(int start_point,vector<vector<int>>& graph){
        int count=0;
        vector<int> e;
        queue<int> q;
        q.push(start_point);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if((*state)[node]==1){
                continue;
            }else{
                if ((*state)[node]==-1){
                    e.push_back(node);
                }
                (*state)[node]=1;
                count++;
                for(int i=0;i<n;i++){
                    if (graph[node][i]==1){
                        q.push(i);
                    }
                }
                
            }
        }
        number.push_back(count);
        neighbours.push_back(e);
    }
};