class Solution {
public:
    //不是很理解这道题考察的啥
    bool isGoodArray(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==1){
            return true;
        }
        for(int i=1;i<nums.size();i++){
            nums[i]=gcd(nums[i],nums[i-1]);
            if(nums[i]==1){
                return true;
            }
        }
        return false;
    }
};
