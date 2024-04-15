class AuthenticationManager {
public:
    int liveTime;
    unordered_map<string,int> map;
    AuthenticationManager(int timeToLive) {
        this->liveTime=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId]=currentTime+this->liveTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(map.count(tokenId) && map[tokenId]>currentTime){
            map[tokenId]=currentTime+liveTime;
        }
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto [key,value]:map){
            if(value>currentTime){
                count++;
            }
        }
        return count;
    }
};
