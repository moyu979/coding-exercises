class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min=100860;
        for(int i=0;i<nums.size()-2;i++){
            int j=nums.size()-1;
            int k=i+1;
            int part=nums[i]+nums[j]+nums[k]-target;
            min=(abs(min)>abs(part)?part:min);
            while(k<j-1){
                if(part>0){
                    j--;
                }else if(part<0){
                    k++;
                }else{
                    return target;
                }
                part=nums[i]+nums[j]+nums[k]-target;
                min=(abs(min)>abs(part)?part:min);
            }
            //min=(abs(min)>abs(part)?part:min);
        }
        return min+target;
    }
};
