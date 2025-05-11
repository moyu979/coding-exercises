#include<vector>
#include<algorithm>
class Solution {
public:
//当到x是确定的，那么引入一个x以下的整数n，到x+n也是确定的
    int getMaximumConsecutive(vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        int t=1;
        int count=1;
        for(int i=0;i<n && coins[i]<=t;i++){
            t=t+coins[i];
        }
        return t;
    }
};