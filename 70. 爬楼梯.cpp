class Solution {
public:
    int climbStairs(int n) {
        int *methods=new int[n+1];
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        methods[1]=1;
        methods[2]=2;
        for(int i=3;i<n+1;i++){
            methods[i]=methods[i-1]+methods[i-2];
        }
        return methods[n];

    }
};