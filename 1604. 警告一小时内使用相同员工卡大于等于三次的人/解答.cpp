#include<algorithm>
class Solution {
public:
struct worker{
    string name;
    vector<int> times;
};
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        
        unordered_map<string,vector<int>> aw;

        vector<string> t;

        for(int i=0;i<keyName.size();i++){
            aw[keyName[i]].emplace_back((keyTime[i][0]-'0')*10*60+(keyTime[i][1]-'0')*60+(keyTime[i][3]-'0')*10+(keyTime[i][4]-'0'));
        }
        for(auto [k,v]:aw){
            if(v.size()<3){
                continue;
            }else if(v.size()>24){
                t.push_back(k);
            }
            else{
                sort(v.begin(),v.end());
                for(int i=0;i<v.size()-2;i++){
                if(v[i+2]-v[i]<=60){
                    t.push_back(k);
                    break;
                }
            }
            }
            
        }
        sort(t.begin(),t.end());
        return t;
    }
};