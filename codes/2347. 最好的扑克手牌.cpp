class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int sum;
        if(suits[0]==suits[1] && suits[0]==suits[2] && suits[0]==suits[3] && suits[0]==suits[4]){
            return "Flush";
        }else{
            sort(ranks.begin(),ranks.end());
            if(ranks[0]==ranks[2] || ranks[1]==ranks[3] || ranks[2]==ranks[4]){
                return "Three of a Kind";
            }else{
                for(int i=0;i<4;i++){
                    if(ranks[i]-ranks[i+1]==0){
                        return "Pair";
                    }
                }
            }
        }
        return "High Card";
    }
};