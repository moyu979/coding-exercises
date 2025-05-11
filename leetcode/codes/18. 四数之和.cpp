#include<algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        vector<vector<int>> ret;
        for(int i=0;i<len-3;){
            for(int j=i+1;j<len-2;){
                long long int tar=(long long)target-nums[i]-nums[j];
                int k=j+1,l=len-1;
                while(k<l){
                    long long int now=nums[k]+nums[l];
                    if(tar==nums[k]+nums[l]){
                        vector<int> a={nums[i],nums[j],nums[k],nums[l]};
                        ret.push_back(a);
                        do{
                            l--;
                        }while(nums[l]==nums[l+1] && k<l);
                        do{
                            k++;
                        }while(nums[k]==nums[k-1] && k<l);
                    }else if(tar<now){
                        do{
                            l--;
                        }while(nums[l]==nums[l+1] && k<l);
                    }else{
                        do{
                            k++;
                        }while(nums[k]==nums[k-1] && k<l);
                    }
                }
                do{
                    j++;
                }while(j<len-2 && nums[j]==nums[j-1]);
            }
            do{
                i++;
            }while(i<len-3 && nums[i]==nums[i-1]);
        }
        return ret;
    }
};