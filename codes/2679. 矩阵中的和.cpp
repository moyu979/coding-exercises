#include<algorithm>
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end(),greater<int>());
        }
        bool conti=false;
        int mark=0;
        int loc=0;
        do{
            conti=false;
            int save=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i].size()>loc && nums[i][loc]>save){
                    conti=true;
                    save=nums[i][loc];
                }
            }
            loc++;
            mark+=save;
        }while(conti);
        return mark;
    }
};