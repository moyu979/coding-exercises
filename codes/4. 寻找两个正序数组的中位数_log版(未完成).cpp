class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int len=m+n;
        int s1=0,s2=0,e1=m-1,e2=n-1;
        //空解
        if(e1==-1){
            if(n%2==1)
                return nums2[n/2];
            else
                return ((float)nums2[n/2]+nums2[n/2-1])/2;
        }
        if(e2==-1){
            if(m%2==1)
                return nums1[m/2];
            else
                return ((float)nums1[m/2]+nums1[m/2-1])/2;
        }
        
        //随机分布解
        int smallgiveup=0;
        while(s1<=e1 && s2<=e2){
            int m1=(s1+e1)/2,m2=(s2+e2)/2,n1=e1-s1+1,n2=e2-s2+1;
            int len=n1+n2;
            //全大/全小解
            if(nums1[s1]>nums2[e2]){
                if(len%2==1){
                    int h=len/2;
                    if(h>=n2)
                        return nums1[s1+h-n2+1];
                    else
                        return nums2[s2+h];
                }
                else{
                    int h=len/2;
                    int h1=h-1;
                    if(h>=n2)
                        h=nums1[s1+h-n2+1];
                    else
                        h=nums2[s2+h];
                    if(h1>=n2)
                        h1=nums1[s1+h1-n2+1];
                    else
                        h1=nums2[s2+h1];
                    return ((float)h+h1)/2;
                }
            }
            if(nums2[s2]>nums1[e1]){
                if(len%2==1){
                    int h=len/2;
                    if(h>=n1)
                        return nums2[s2+h-n1+1];
                    else
                        return nums1[s1+h];
                }
                else{
                    int h=len/2;
                    int h1=h-1;
                    if(h>=n1)
                        h=nums2[s2+h-n1+1];
                    else
                        h=nums1[s1+h];
                    if(h1>=n1)
                        h1=nums2[s2+h1-n1+1];
                    else
                        h1=nums1[s1+h1];
                    return ((float)h+h1)/2;
                }
            }
            if(nums1[m1]<nums2[m2]){
                s1=m1+1;
                e2=m2-1;
            }
            if(nums1[m1]>nums2[m2]){
                e1=m1-1;
                s2=m2+1;
            }
            if(nums1[m1]==nums2[m2]){
                return nums1[m1];
            }
        }
        if(s1<=e1){
            len=(e2-s2+1);
            if(len%2==0){
                return ((float)nums2[s2+len/2] + nums2[s2+len/2-1])/2;
            }else{
                return nums2[s2+len/2];
            }
        }
        if(s2<=e2){
            len=(e1-s1+1);
            if(len%2==0){
                return ((float)nums1[s1+len/2] + nums1[s1+len/2-1])/2;
            }else{
                return nums1[s1+len/2];
            }
        }
        return 0;
        //o(m+n)
        // int* nums=new int[len];
        // int s1=0,s2=0;
        // int k=0;
        // while(s1!=m && s2!=n){
        //     if(nums1[s1]<nums2[s2]){
        //         nums[k]=nums1[s1];
        //         s1++;
        //     }else{
        //         nums[k]=nums2[s2];
        //         s2++;
        //     }
        //     k++;
        // }
        // if(s2!=n){
        //     for(;s2<n;s2++){
        //         nums[k]=nums2[s2];
        //         k++;
        //     }
        // }
        // if(s1!=m){
        //     for(;s1<m;s1++){
        //         nums[k]=nums1[s1];
        //         k++;
        //     }
        // }
        // if(len%2==1){
        //     return nums[len/2];
        // }else{
        //     return ((float)nums[len/2]+(float)nums[len/2-1])/2;
        // }
    }
};
