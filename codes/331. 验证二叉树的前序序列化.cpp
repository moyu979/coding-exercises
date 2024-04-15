class Solution {
public:
    int n;
    bool isValidSerialization(string preorder) {
        vector<string> ss=split(preorder);
        n=ss.size();
        int end=0;
        bool jieshu=diedai(ss,0,end);
        if(end==n-1){
            return jieshu;
        }else{
            return false;
        }
        return true;
    }

    bool diedai(vector<string> &s,int start,int& end){
        end=start;
        if (start>=n){
            return false;
        }
        if(s[start]=="#"){
            return true;
        }else{
            int newstart=0;
            bool first=diedai(s,start+1,newstart);
            bool second=diedai(s,newstart+1,end);
            if(!first || !second){
                return false;
            }
            return true;
        }
        return false;
    }

    vector<string> split(string s){
        vector<string> ss;
        string sss="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=','){
                sss=sss+s[i];
            }else{
                ss.push_back(sss);
                sss="";
            }
        }
        ss.push_back(sss);
        return ss;
    }
};