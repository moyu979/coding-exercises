class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string map[8][4]={{"a","b","c",""},
                        {"d","e","f",""},
                        {"g","h","i",""},
                        {"j","k","l",""},
                        {"m","n","o",""},
                        {"p","q","r","s"},
                        {"t","u","v",""},
                        {"w","x","y","z"}};
        if(digits.length()==0){
            return ans;
        }
        int n=digits[0]-'2';
        for(int i=0;i<4  && map[n][i].length()!=0;i++){
            ans.push_back(map[n][i]);
        }
        
        for(int i=1;i<digits.length();i++){
            vector<string> temp;
            int n=digits[i]-'2';
            for(int j=ans.size()-1;j>-1;j--){
                string s=ans[j];
                for(int k=0;k<4 && map[n][k].length()!=0;k++){
                    temp.push_back(s+map[n][k]);
                }
            }
            ans.swap(temp);
        }
        return ans;
    }
};