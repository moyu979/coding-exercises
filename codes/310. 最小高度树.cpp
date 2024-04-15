class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            vector<int> q1;
            q1.push_back(0);
            return q1;
        }
        vector<int> q1,q2;
        vector<int> *p1=&q1,*p2=&q2;

        vector<int> degree(n);
        vector<vector<int>> matrix(n);

        for(auto edge:edges){
            matrix[edge[0]].push_back(edge[1]);
            matrix[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q1.push_back(i);
                degree[i]=-1;
            }
        }
        while(p1->size()!=0){
            bool all_one=true;
            for(int i=0;i<n;i++){
                if(degree[i]!=-1){
                    all_one=false;
                    break;
                }
            }
            if(all_one){
                return *p1;
            }
            for(int i:*p1){
                for(int j:matrix[i]){
                    if(degree[j]==-1){
                        continue;
                    }else{
                        degree[j]--;
                        if(degree[j]==1){
                            p2->push_back(j);
                            degree[j]=-1;
                        }
                    }
                    
                }
            }
            p1->clear();
        
            vector<int>* temp=p1;
            p1=p2;
            p2=temp;
        }
        return q1;
    }
};