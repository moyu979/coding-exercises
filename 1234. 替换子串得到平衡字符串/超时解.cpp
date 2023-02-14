class Solution {
public:
//假设有X字符多出a个，则子串中的x字符应该有a个，字符串的长度最小，应该为多出来的数量之和，并将这些转化成缺少的字符
//可以讨论这a个字符的间隔，
    int balancedString(string s) {
        int slen=s.length();
        int num=slen/4;
        int count[]={0,0,0,0};
        int len=slen;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case 'Q':{
                    count[0]++;
                    break;
                }
                case 'W':{
                    count[1]++;
                    break;
                }
                case 'E':{
                    count[2]++;
                    break;
                }  
                case 'R':{
                    count[3]++;
                    break;
                }  
            }
            
        }
        int less=0;
        bool test=true;
        for(int i=0;i<4;i++){
            if(count[i]>num){
                less=less+count[i]-num;
                test=false;
            }
        }
        if(test){
            return 0;
        }
        for(int i=0;i<slen;i++){
            int temp[]={0,0,0,0};
            for(int k=i;k-i+1<len && k<slen;k++){
                switch(s[k]){
                    case 'Q':{
                        temp[0]+=1;
                        break;
                    }
                    case 'W':{
                        temp[1]+=1;
                        break;
                    }
                    case 'E':{
                        temp[2]+=1;
                        break;
                    }  
                    case 'R':{
                        temp[3]+=1;
                        break;
                    } 
                    default:
                        ;
                }
                bool change=true;
                for(int j=0;j<4;j++){
                    if(count[j]-temp[j]>num){
                        change=false;
                        break;
                    }
                }
                if(change){
                    if(len>k-i){
                        len=k-i+1;
                        break;
                    }
                }
            }
        }
        return len;
    }
};
