class Solution {
public:
    string convert(string s, int numRows) {
        string as="";
        int n=s.length();
        if(numRows==1){
            return s;
        }
        int T=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            int addon=2*i;
            if(addon==0){
                addon=T;
            }
            for(int j=i;j<n;j+=addon){
                as+=s[j];
                if(addon!=T){
                    addon=T-addon;
                }
                
            }
            
        }
        cout<<as;
        return as;
    }
};