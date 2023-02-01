class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        o(m+n)
        int* nums=new int[len];
        int s1=0,s2=0;
        int k=0;
        while(s1!=m && s2!=n){
            if(nums1[s1]<nums2[s2]){
                nums[k]=nums1[s1];
                s1++;
            }else{
                nums[k]=nums2[s2];
                s2++;
            }
            k++;
        }
        if(s2!=n){
            for(;s2<n;s2++){
                nums[k]=nums2[s2];
                k++;
            }
        }
        if(s1!=m){
            for(;s1<m;s1++){
                nums[k]=nums1[s1];
                k++;
            }
        }
        if(len%2==1){
            return nums[len/2];
        }else{
            return ((float)nums[len/2]+(float)nums[len/2-1])/2;
        }
    }
};
