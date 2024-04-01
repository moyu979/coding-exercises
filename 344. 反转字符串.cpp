class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size()-1;
        //cout<<n<<endl;
        for(int i=n/2;i>=0;i--){
            //cout<<i<<endl;
            char t=s[i];
            s[i]=s[n-i];
            s[n-i]=t;
        }
    }
};