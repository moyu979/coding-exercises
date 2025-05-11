class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int humans=accounts.size();
        int* wealth=new int[humans];
        for(int i=0;i<humans;i++){
            wealth[i]=0;
        }
        for(int i=0;i<humans;i++){
            int banks=accounts[i].size();
            for(int j=0;j<banks;j++){
                wealth[i]+=accounts[i][j];
            }
        }
        int most=0;
        for(int i=0;i<humans;i++){
            if(wealth[i]>most){
                most=wealth[i];
            }
        }
        return most;
    }
};