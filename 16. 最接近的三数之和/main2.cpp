
#include<algorithm>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int temp=100000;
        vector<int> a;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(abs(nums[i]+nums[j]+nums[k]-target)<temp){
                    temp=abs(nums[i]+nums[j]+nums[k]-target);
                    vector<int> b={i,j,k};
                    a=b;
                }
                if(nums[i]+nums[j]+nums[k]-target<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return nums[a[0]]+nums[a[1]]+nums[a[2]];
    }
};