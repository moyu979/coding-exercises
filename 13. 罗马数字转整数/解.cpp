class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        int num=0;
        while(n>=0){
            switch(s[n]){
                case 'I':
                    num+=1;
                    break;
                case 'V':
                    if(n>0 && s[n-1]=='I'){
                        num+=4;
                        n--;
                    }else{
                        num+=5;
                    }
                    break;
                case 'X':
                    if(n>0 && s[n-1]=='I'){
                        num+=9;
                        n--;
                    }else{
                        num+=10;
                    }
                    break;
                case 'L':
                    if(n>0 && s[n-1]=='X'){
                        num+=40;
                        n--;
                    }else{
                        num+=50;
                    }
                    break;
                case 'C':
                    if(n>0 && s[n-1]=='X'){
                        num+=90;
                        n--;
                    }else{
                        num+=100;
                    }
                    break;
                case 'D':
                    if(n>0 && s[n-1]=='C'){
                        num+=400;
                        n--;
                    }else{
                        num+=500;
                    }
                    break;
                case 'M':
                    if(n>0 && s[n-1]=='C'){
                        num+=900;
                        n--;
                    }else{
                        num+=1000;
                    }
                    break;
                default:
                    ;
            }
            n--;
        }
        return num;
    }
};