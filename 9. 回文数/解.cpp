class Solution {
public:
    bool isPalindrome(int x) {
        int y=0, z=x;
        if(x<0){
            return false;
        }
        while(z){
            if(y>214748364){
                return false;
            }
            y*=10;
            y=y+z%10;
            z=z/10;
        }
        return x-y==0?true:false;
    }
};