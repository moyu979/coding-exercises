class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int count=0;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(i<len-1 && nums[i]==nums[i+1]){
                count++;
                i++;
            }
        }
        vector<int> r(2);
        r[0]=count;
        r[1]=len-count*2;
        return r;
    }
};