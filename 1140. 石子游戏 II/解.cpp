class Solution {
public:
    vector<int> piles;
    int alice;
    int matrix[102][64][2];
    int stoneGameII(vector<int>& piles) {
        this->piles=piles;
        alice=0;
        for(int i=0;i<102;i++){
            for(int j=0;j<64;j++){
                for(int k=0;k<2;k++){
                    matrix[i][j][k]=-1;
                }
            }
        }
        return getMax(0,1,true);
    }
    //让对方之后能拿到的总数最小，并返回此时我方拿到的石头数
    int getMax(int start,int m,bool player){
        if(start>=piles.size()){
            return 0;
        }

        int min=1008611;//下次对方取的最大值的最小值
        int mi=1;       //下次对方取的最大值的最小值的位置

        for(int i=1;i<=2*m;i++){
            int nm=m>i?m:i;
            if(start+nm>piles.size()){
                nm=piles.size()-start;
            }
            int p=0;
            if(player){
                p=1;
            }

            int max;
            int x1=start+i>piles.size()?piles.size():start+i;
            //printf("%d,%d,%d\n",x1,nm,p);
            if(matrix[x1][nm][p]==-1){
                matrix[x1][nm][p]=getMax(x1,nm,!player);
            }
            max=matrix[x1][nm][p];

            if(max<min){
                min=max;
                mi=i;
            }
            
        }
        int self=0;
        for(int i=start+mi;i<piles.size();i++){
            self=self+piles[i];
        }self=self-min;
        //算出来了mi时，让对方最大石子数最小
        for(int i=start;i<start+mi;i++){
            self+=piles[i];
        }

        return self;
    }
};