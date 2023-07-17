class Solution {
public:
    string addStrings(string num1, string num2) {
        int coefficient=1,l1=num1.length(),l2=num2.length();
        string result="";
        int temp=0;
        for(int i=0;i<l1 || i<l2;i++){
            if(i<l1){
                temp=temp+num1[l1-i-1]-'0';
            }
            if(i<l2){
                temp=temp+num2[l2-i-1]-'0';
            }
            char t=temp%10+'0';
            result=t+result;
            temp=temp/10;
        } 
        if(temp!=0){
            char t=temp%10+'0';
            result=t+result;
        }
        return result;

    }
};