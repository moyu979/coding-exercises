#include<queue>
class Solution {
public:
    vector<int> *edge;
    int n;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n=n;
        edge=new vector<int>[n];
        for(vector<int> a:edges){
            edge[a[0]].push_back(a[1]);
            edge[a[1]].push_back(a[0]);
        }
        int * ret=new int[n];
        for(int i=0;i<n;i++){
            ret[i]=dfs(i,edge);
            cout<<endl;
        }
        vector<int> to;
        for(int i=0;i<n;i++){
            to.push_back(ret[i]);
        }
        return to;
    }
    int dfs(int rootNode,vector<int>* edge){
        int length=0;
        int startCount=0;
        bool *visited=new bool[n];
        queue<int> que;
        int now=rootNode;

        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        
        que.push(rootNode);
        visited[rootNode]=true;
        while(!que.empty()){

            length+=startCount;

            int toV=que.front();
            que.pop();

            for(int i:edge[toV]){
                if(!visited[i]){
                    visited[i]=true;
                    que.push(i);
                }
            }
            if(toV==now){
                startCount++;
                now=que.back();
            }
        }
        return length;
    }
};