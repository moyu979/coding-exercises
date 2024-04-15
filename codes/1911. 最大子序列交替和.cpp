#include<algorithm>
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ret;
        int size=nums.size();
        long long int *mar=new long long int[2];
        mar[0]=nums[0];
        mar[1]=0;
        long long int beforeodd=mar[1];
        long long int beforeeven=mar[0];
        for(int i=1;i<size;i++){
            beforeodd=mar[1];
            beforeeven=mar[0];
            mar[0]=max(beforeeven,beforeodd+nums[i]);
            mar[1]=max(beforeodd,beforeeven-nums[i]);
        }
        return max(mar[0],mar[1]);

        

    }
};