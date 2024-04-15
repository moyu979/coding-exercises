class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n=nums.size();
        if(n==0){
            return ret;
        }
        string s=to_string(nums[0]);
        if(n==1){
            ret.push_back(s);
            return ret;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i]){
                ;
            }else if(i==1 || nums[i-2]+1!=nums[i-1]){
                ret.push_back(s);
                s=to_string(nums[i]);
            }else{
                s=s+"->"+to_string(nums[i-1]);
                ret.push_back(s);
                s=to_string(nums[i]);
            }
        }
        if(nums[n-1]==nums[n-2]+1){
            s=s+"->"+to_string(nums[n-1]);
        }
        ret.push_back(s);
        return ret;
    }
};