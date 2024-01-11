class Solution {
public:
    int minLength(string s) {
        /*string t=s;
        for(int i=0;i<t.length()-1;i++){
            i=(i>=0?i:0);
            if(t[i]=='A' && t[i+1]=='B'){
                t=t.erase(i,2);
                i-=2;
            }
            else if(t[i]=='C' && t[i+1]=='D'){
                t=t.erase(i,2);
                i-=2;
            }
            
        }
        cout<<t;
        return t.length();*/
        string t=s;
        int it=0;
        while(it!=t.length()){
            it=t.length();
            for(int i=0;i<t.length();i++){
                if(t[i]=='A' && t[i+1]=='B'){
                t=t.erase(i,2);
                }
            else if(t[i]=='C' && t[i+1]=='D'){
                t=t.erase(i,2);
            }
            }
            
        }
        return it;
        
    }
};