class NumArray {
public:
    vector<int> k;
    NumArray(vector<int>& nums) {
        k=nums;
    }
    
    int sumRange(int left, int right) {
        int temp=0;
        for(int i=left;i<=right;i++){
            temp+=k[i];
        }
        return temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */