class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int hl=height[left],hr=height[right];
        int water=0;
        while(left<right){
            //cout<<"water:"<<water<<" left:"<<left<<" hl:"<<hl<<" right"<<right<<" hr:"<<hr<<endl;
            if(hl<hr){
                left++;
                if(left==height.size()-1 || height[left]>=height[left-1] && height[left]>height[left+1] && height[left]>hl){
                    hl=height[left];
                    continue;
                }else if(hl>height[left]){
                    water=water+(hl-height[left]);
                }
            }else{
                right--;
                if(right==0 || (height[right]>=height[right-1] && height[right]>height[right+1] && height[right]>hr)){
                    hr=height[right];
                    continue;
                }else if(hr>height[right]){
                    water=water+(hr-height[right]);
                }
            }
            
        }
        return water;
    }
};