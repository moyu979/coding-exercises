class Solution {
public:
long int max=2147483647,min=-2147483648;
    int myAtoi(string s) {
        long long int number=0;
        bool sign=false;
        bool flag=true;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && flag){
                continue;
            }else if(s[i]=='-' && flag){
                sign=true;
                flag=false;
            }else if(s[i]=='+' && flag){
                flag=false;
            }else if (s[i]>'0'-1 && s[i]<'9'+1){
                number=number*10;
                number=number+s[i]-'0';
                if (number>max+1){
                    if(sign){
                        return min;
                    }else{
                        return max;
                    }
                }
                flag=false;
            }else{
                break;
            }
        }
        if(sign){
            number=-number;
        }
        if(number>max)
            return max;
        else if(number<min){
            return min;
        }else{
            return int(number);
        }
        return 0;
    }
};