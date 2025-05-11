class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            //cout<<nums1[i]<<" "<<nums2[j]<<endl;
            if(nums1[i]<=nums2[j]){
                //cout<<"1 "<<nums2[j]<<endl;
                nums1[k]=nums2[j];
                j--;
            }else{
                //cout<<"2 "<<nums1[i]<<endl;
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }
        if(i>=0){
            while(i>=0){
                nums1[k]=nums1[i];
                i--;
                k--;
            }
        }else{
            while(j>=0){
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
    }
};