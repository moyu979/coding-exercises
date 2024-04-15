class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int start=0,end=0,count=0,len=0;
        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                count++;
            }else{
                count--;
            }
        }
        if(count>0){
            return hours.size();
        }
        for(int start=0;start<hours.size();start++){
            int c=count;
            if(c>0 && hours.size()-start>len){
                return hours.size()-start;
            }
            for(int j=hours.size();j>start+len;j--){
                if(hours[j-1]>8){
                    c--;
                }else{
                    c++;
                }
                if(c>0 && j-start>len){
                    len=j-start-1;
                    break;
                }else if(c>0){
                    break;
                }
            }
            if(hours[start]>8){
                count--;
            }else{
                count++;
            }
        }
        return len;
    }
};