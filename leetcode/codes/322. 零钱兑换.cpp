class Solution {
public:
    const int nul=100000;
    int coinChange(vector<int>& coins, int amount) {
        int* n=new int[amount+1];
        n[0]=0;
        for(int i=1;i<amount+1;i++){
            n[i]=nul;
            for(auto coin:coins){
                if(i-coin>=0 && n[i-coin]!=nul){
                    n[i]=min(n[i-coin]+1,n[i]);
                }
            }
        }
        return n[amount]==nul?-1:n[amount];
        
    }
};