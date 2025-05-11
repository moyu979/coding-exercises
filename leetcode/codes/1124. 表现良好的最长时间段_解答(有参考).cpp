class Solution {
public:
    int longestWPI(vector<int>& hours) {
        //queue<int> s;
        stack<int> s;
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<=hours.size();i++){
            v.push_back(v[i-1]+(hours[i-1]>8?1:-1));
        }
        for(int i=hours.size();i>0;i--){
            if(s.empty() || v[s.top()]<v[i]){
                s.push(i);
                printf("vi %d\t",v[i]);
            }
        }printf("\n");
        int len=0;
        for(int i=0;i<v.size();i++){
            while(!s.empty() && v[s.top()]>v[i]){
                len=max(len,s.top()-i);
                s.pop();
                printf("%d\t",len);
            }
        }
        return len;
    }

};