class Solution {
public:
//当到x是确定的，那么引入一个x以下的整数n，到x+n也是确定的
    int getMaximumConsecutive(vector<int>& coins) {
        int n=coins.size();
        sort(coins);
        int t=1;
        int count=1;
        for(int i=0;i<n && coins[i]<=t;i++){
            t=t+coins[i];
        }

        return t;
    }

    void sort(vector<int>& coins){
        for(int i=0;i<coins.size();i++){
            for(int j=1+i;j<coins.size();j++){
                if(coins[i]>coins[j]){
                    int temp=coins[i];
                    coins[i]=coins[j];
                    coins[j]=temp;
                }
            }
        }
    }
};