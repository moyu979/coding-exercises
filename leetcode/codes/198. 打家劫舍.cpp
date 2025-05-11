class Solution {
public:
    int rob(vector<int>& nums) {
        int temp[2][3];
        temp[0][0]=0;
        temp[1][0]=nums[0];
        for(int i=1;i<nums.size();i++){
            temp[0][i%3]=max(temp[1][(i+2)%3],temp[0][(i+2)%3]);
            temp[1][i%3]=temp[0][(i+2)%3]+nums[i];
        }
        return max(temp[0][(nums.size()-1)%3],temp[1][(nums.size()-1)%3]);
    }
};