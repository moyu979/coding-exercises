#include<algorithm>
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int size=matrix.size();
        int *a=new int[size];
        int *b=new int[size];
        for(int i=0;i<size;i++){
            a[i]=matrix[size-1][i];
            b[i]=0;
        }
        for(int i=size-2;i>=0;i--){
            for(int j=0;j<size;j++){
                if(j==0){
                    b[j]=min(a[0],a[1])+matrix[i][j];
                }else if(j==size-1){
                    b[j]=min(a[size-1],a[size-2])+matrix[i][j];
                }else{
                    int minit=a[j-1];
                    minit=min(minit,a[j]);
                    minit=min(minit,a[j+1]);
                    b[j]=minit+matrix[i][j];
                }
            }
            int *c=a;
            a=b;
            b=c;
        }
        int minit=a[0];
        for(int i=0;i<size;i++){
            minit=min(minit,a[i]);
        }
        return minit;
    }
};