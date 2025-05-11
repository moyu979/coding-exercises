class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> p;
        for(int i=0;i<26;i++){
            p[i]=0;
        }
        int i=0,j=0,max=0;
        while(j<s.length()){
            p[s[j]]++;
            j++;
            while(p[s[j-1]]>1){
                p[s[i]]--;
                i++;
            }
            //printf("%d\t",(j-i));
            max=max>(j-i)?max:(j-i);
        }
        return max;
    }
};