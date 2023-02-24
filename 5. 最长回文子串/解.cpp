class Solution {
public:
    string longestPalindrome(string s) {
        int max=0,ml,mr;
        for(int i=0;i<s.length();i++){
            //中心扩散
            for(int j=0;i-j>=0 && i+j<s.length();j++){
                if(s[i-j]==s[i+j] && max<2*j+1){
                    max=(2*j+1);
                    printf("%d\t",max);
                    ml=(i-j);
                    mr=(i+j);
                }else if(s[i-j]!=s[i+j]){
                    break;
                }
            }
            for(int j=0;i-j>=0 && i+j+1<s.length();j++){
                if(s[i-j]==s[i+j+1] && max<2*j+2){
                    max=(2*j+2);
                    ml=(i-j);
                    mr=(i+j+1);
                }else if(s[i-j]!=s[i+j+1]){
                    break;
                }
            }
        }
        printf("%d",max);
        return s.substr(ml,mr-ml+1);
    }
};