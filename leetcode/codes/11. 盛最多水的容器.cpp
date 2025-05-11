class Solution {
public:
    //如果一个点高h，作为容器的左壁，它后面比它更低的点没必要考虑
    //如果一个点高h，作为容器的右壁，它前面比它更低的点没必要考虑
    //
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int max=0;
        while(i<j){
            int s=min(height[i],height[j])*(j-i);
            if(max<s){
                max=s;
                //printf("%d,%d,%d\n",max,i,j);
            }
            if(height[i]<height[j]){
                int m=i;
                while(height[i]<=height[m] && i<j){
                    i++;
                }
            }else if (height[i]>height[j]){
                int m=j;
                while(height[m]>=height[j] && i<j){
                    j--;
                }
            }else{
                i++;
            }
        }
        // int n=height.size(),m=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int s=min(height[i],height[j])*(j-i);
        //         m=m>s?m:s;
        //     }
        // }
        return max;
    }
};