class Solution {
public:
    vector<vector<int>> nowColorl[2];
    vector<vector<int>> nowColor;
    queue<int> v;
    bool* visit[2];
    vector<int> rs;
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        visit[0]=new bool[n];
        visit[1]=new bool[n];
        queue<int> v=*(new queue<int>);
        nowColorl[0]=redEdges;
        nowColorl[1]=blueEdges;
        for(int i=0;i<n;i++){
            visit[1][i]=false;
            visit[0][i]=false;
            rs.push_back(-1);
        }
        rs[0]=0;
        nowColor=redEdges;
        
        guangduyouxian(0);
        for(int i=0;i<n;i++){
            visit[1][i]=false;
            visit[0][i]=false;
        }
        guangduyouxian(1);
        return rs;
    }
    void guangduyouxian(int start){
        v.push(0);
        int door=0,nextdoor=0;
        int i;
        int count=0;
        while(!v.empty()){
            count++;
            nowColor=nowColorl[(start+count)%2];
            door=nextdoor;
            do{
                i=v.front();
                v.pop();
                for(int j=0;j<nowColor.size();j++){
                    if(nowColor[j][0]==i && !visit[(start+count)%2][nowColor[j][1]]){
                        if(rs[nowColor[j][1]]==-1 || rs[nowColor[j][1]]>count){
                            rs[nowColor[j][1]]=count;
                        }
                        visit[(start+count)%2][nowColor[j][1]]=true;
                        nextdoor=nowColor[j][1];
                        v.push(nowColor[j][1]);
                    }
                }
            }while(i!=door);
        }
        
    }
};