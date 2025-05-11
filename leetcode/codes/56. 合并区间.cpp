#include<algorithm>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size();){
            int start=intervals[i][0],end=intervals[i][1];
            while(i<intervals.size() && intervals[i][0]<=end){
                if(intervals[i][1]>end){
                    end=intervals[i][1];
                }
                i++;
            }
            vector<int> t(2);
            t[0]=start;
            t[1]=end;
            ret.push_back(t);
        }
        return ret;
    }
};