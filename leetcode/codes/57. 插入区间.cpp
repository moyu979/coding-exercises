class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start=newInterval[0],end=newInterval[1],count=0;
        auto i=intervals.begin(),j=intervals.begin();
        while(j!=intervals.end()){
            if((*j)[1]<start){
                j++;i++;
            }else if((*j)[0]>end){
                break;
            }else{
                start=min(start,(*j)[0]);
                end=max(end,(*j)[1]);
                j++;
            }

        }
        vector<int> t(2);
        t[0]=start;
        t[1]=end;
        j=intervals.erase(i,j);
        intervals.insert(j,t);
        return intervals;
    }
};