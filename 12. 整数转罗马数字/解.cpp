class Solution {
public:
    string intToRoman(int num) {
        string jie="";
        int tens=0;
        string map[4][2]={{"I","V"},
                        {"X","L"},
                        {"C","D"},
                        {"M","0"}};
        while(num!=0){
            int temp=num%10;
            num=num/10;
            switch(temp){
                case 4:
                    jie=""+map[tens][0]+map[tens][1]+jie;
                    break;
                case 9:
                    jie=""+map[tens][0]+map[tens+1][0]+jie;
                    break;
                case 3:
                    jie=""+map[tens][0]+jie;
                case 2:
                    jie=""+map[tens][0]+jie;
                case 1:
                    jie=""+map[tens][0]+jie;
                    break;
                case 8:
                     jie=""+map[tens][0]+jie;
                case 7:
                    jie=""+map[tens][0]+jie;
                case 6:
                    jie=""+map[tens][0]+jie;
                case 5:
                    jie=""+map[tens][1]+jie;
                    break;
                default:
                    ;
            }
            tens++;
        }
        return jie;
    }
};