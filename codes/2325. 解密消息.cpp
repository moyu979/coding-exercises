class Solution {
public:
    string decodeMessage(string key, string message) {
        int len=key.length();
        char match[26];
        for(int i=0;i<26;i++){
            match[i]=' ';
        }
        int count=0;
        for(int i=0;i<len;i++){
            if(key[i]==' '){
                continue;
            }else{
                int loc=key[i]-'a';
                if(match[loc]==' '){
                    match[loc]=count+'a';
                    count++;
                }
            }
            
        }
        for(int i=0;i<message.length();i++){
            if(message[i]==' '){
                continue;
            }else{
                int loc=message[i]-'a';
                message[i]=match[loc];
            }
            
        }
        return message;
    }
};
