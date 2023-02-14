class Solution {
public:
    string alphabetBoardPath(string target) {
        string toRet="";
        int now[]={0,0};
        for(int i=0;i<target.length();i++){
            int size=target[i]-'a';
            int x=size%5;
            int y=size/5;
            while(now[1]>x){
                toRet+="L";
                now[1]--;
            }
            while(now[0]<y){
                toRet+="D";
                now[0]++;
            }
            while(now[0]>y){
                toRet+="U";
                now[0]--;
            }
            while(now[1]<x){
                toRet+="R";
                now[1]++;
            }

            toRet+="!";
        }
        return toRet;
    }
};
