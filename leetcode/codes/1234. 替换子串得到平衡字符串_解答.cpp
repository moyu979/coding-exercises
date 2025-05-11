class Solution {
public:
//假设有X字符多出a个，则子串中的x字符应该有a个，字符串的长度最小，应该为多出来的数量之和，并将这些转化成缺少的字符
//可以讨论这a个字符的间隔，
    int balancedString(string s) {
        int slen=s.length();
        int num=slen/4;
        int count[]={0,0,0,0};
        int len=slen;
        //计数
        for(int i=0;i<s.length();i++){
            count[getnum(s[i])]++;
        }
        //统计最少移动多少
        int less=0;
        bool test=true;//是否平衡的flag
        for(int i=0;i<4;i++){
            if(count[i]>num){
                less=less+count[i]-num;
                test=false;
            }
        }
        //不变直接反0
        if(test){
            return 0;
        }
        for(int i=0;i<=slen-less;i++){

            int temp[]={0,0,0,0};
            //以i为起点不断增长，直到产生匹配项或到了现在已有的长度还没匹配上，再长的话就算匹配上，也不是最小的了
            for(int k=i;k-i+1<len && k<slen;k++){
                temp[getnum(s[k])]++;//统计此时各字母出现了多少
                //如果都剩下的都小于等于需要的，改里面就可行
                bool change=true;
                for(int j=0;j<4;j++){
                    if(count[j]-temp[j]>num){
                        change=false;
                        break;
                    }
                }
                //如果都小于，现在长度合适，如果能更新最小长度，就更新。
                if(change){
                    if(len>k-i+1){
                        len=k-i+1;
                    }
                    break;
                }
            }

            //在上文已经找到了以i为起点的最小字符串，下面看这个字符串能不能后移而无需再次匹配
            //关键！类似字符串匹配的改进算法，相同时直接后滑，无需再次比对,否则时间会超。
            while(i+len<=slen && i<slen){
                int flag=getnum(s[i]);
                //如果i位置的字符很多，移出这个字符，就要看尾字符能不能补进来
                if(count[flag]>num && s[i+len]==s[i]){
                    i++;
                }else if(count[flag]<=num && s[i+1]==s[i]){
                    i++;
                    //len--;
                }else{
                    break;
                }
            }
        }
        return len;
    }
    int getnum(char c){
        switch(c){
            case 'Q':
                return 0;
            case 'W':
                return 1;
            case 'E':
                return 2;
            case 'R':
                return 3;
            default:
                return -1;
        }
    }
};
返回该题
力扣 LeetCode
竞赛
LeetBook
讨论社区
求职
Plus 会员
周边商城
企业服务