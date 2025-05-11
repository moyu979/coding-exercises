class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //空状态，冷却状态，持有状态
        /*状态转移：
        空状态是上一个空状态或冷却状态结束得到的
        冷却状态是上一个态卖出得到的
        持有状态继承自上一个空状态或冷却态买入或继续持有
        */
        int* a[2];
        a[0]=new int[3]{0,0,-1*prices[0]};
        a[1]=new int[3];
        int lastp=0;
        for(int i=1;i<prices.size();i++){
            int now=i%2,before=(i-1)%2;
            a[now][0]=max(a[before][0],a[before][1]);
            a[now][1]=a[before][2]+prices[i];
            if(a[before][0]-prices[i]>a[before][2]){
                lastp=prices[i];
            }
            a[now][2]=max(a[before][0]-prices[i],a[before][2]);
        }

        int now=(prices.size()-1)%2;
        a[now][2]+=lastp;
        lastp=0;
        for(int i=0;i<3;i++){
            lastp=max(lastp,a[now][i]);
        }
        return lastp;


    }
};