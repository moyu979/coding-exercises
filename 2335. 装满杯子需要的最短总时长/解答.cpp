class Solution {
public:
    int fillCups(vector<int>& amount) {
        int times=0;
        int minloc=-1,minval=1000;
        while(true){
        //while(sum(amount)!=0){
            int count=0;
            for(int i=0;i<3;i++){
                count+=amount[i];
            }
            if(count==0){
                break;
            }
            for(int i=0;i<3;i++){
                if(minval>amount[i]){
                    minval=amount[i];
                    minloc=i;
                }
            }
            for(int i=0;i<3;i++){
                if(i!=minloc && amount[i]!=0){
                    amount[i]--;
                }    
            }
            times++;
        }
        return times;
    }
    int sum(vector<int>& amount){
        int count=0;
        for(int i=0;i<3;i++){
            count+=amount[i];
        }
        return count;
    }
    
};