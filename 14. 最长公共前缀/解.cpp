class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int max=10086;
        for(int i=0;i<strs.size();i++){
            if(max>strs[i].length()){
                max=strs[i].length();
            }
        }
        int i=0;
        for(i=0;i<max;i++){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=c){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0].substr(0,max);
    }
};