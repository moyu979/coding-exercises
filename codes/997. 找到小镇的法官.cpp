class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> believe(n+1),bebelieve(n+1);
        for(auto a:trust){
            bebelieve[a[1]]++;
            believe[a[0]]++;
        }
        for(int i=1;i<n+1;i++){
            if(bebelieve[i]==n-1 && believe[i]==0){
                return i;
            }
        }
        return -1;
    }
};