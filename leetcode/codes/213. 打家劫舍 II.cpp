class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int ma;
        int temp[2][3];
        temp[0][2]=0;
        temp[1][2]=0;
        
        temp[0][0]=0;
        temp[1][0]=0;
        temp[0][1]=0;
        temp[1][1]=nums[1];
        for(int i=2;i<nums.size();i++){
            temp[0][i%3]=max(temp[1][(i+2)%3],temp[0][(i+2)%3]);
            temp[1][i%3]=temp[0][(i+2)%3]+nums[i];
        }
        ma=max(temp[0][(nums.size()-1)%3],temp[1][(nums.size()-1)%3]);
        cout<<ma;
        temp[0][2]=0;
        temp[1][2]=0;
        temp[0][0]=nums[0];
        temp[1][0]=nums[0];
        temp[0][1]=nums[0];
        temp[1][1]=nums[0];
        for(int i=2;i<nums.size();i++){
            temp[0][i%3]=max(temp[1][(i+2)%3],temp[0][(i+2)%3]);
            temp[1][i%3]=temp[0][(i+2)%3]+nums[i];
        }
        ma=max(temp[0][(nums.size()+1)%3],temp[1][(nums.size()+1)%3])>ma?max(temp[0][(nums.size()+1)%3],temp[1][(nums.size()+1)%3]):ma;
        return ma;
    }
};