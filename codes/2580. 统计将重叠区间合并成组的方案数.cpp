#include<algorithm>
class Solution {
public:
    int mode=1000000007;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int differents=1;
        int start=-1,end=-1;
        int n=ranges.size();
        int now=0;
        while (now<n){
            if(start==-1){
                start=ranges[now][0];
                end=ranges[now][1];
            }else{
                if(ranges[now][0]<=end){
                    end=max(end,ranges[now][1]);
                }else{
                    differents++;
                    start=ranges[now][0];
                    end=ranges[now][1];
                }

            }
            now++;
        }
        
        cout<<differents;
        int result=1;
        while(differents>0){
            result=result*2;
            result=result%mode;
            differents--;
        }
        return result;
    }
};