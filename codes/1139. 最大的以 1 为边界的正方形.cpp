class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int len[102][102][2];
        int max=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                len[i][j][0]=0;
                len[i][j][1]=0;
            }    
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){//计边长
                    len[i+1][j+1][0]=0;
                    len[i+1][j+1][1]=0;
                }else{
                    len[i+1][j+1][0]=len[i+1][j][0]+1;
                    len[i+1][j+1][1]=len[i][j+1][1]+1;
                }
            }    
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    continue;
                }else{
                    int size=min(len[i+1][j+1][0],len[i+1][j+1][1]);
                    if(size<max){
                        continue;
                    }
                    while(size>0){
                        if(i-size+1<0 || j-size+1<0){
                            printf("%d,%d,%d",i,j,size);
                        }
                        if(grid[i-size+1][j-size+1]==0){
                            ;
                        }
                        else if(len[i+1][j-size+2][1]-len[i-size+1][j-size+2][1]==size && len[i-size+2][j+1][0]-len[i-size+2][j-size+1][0]==size){
                            break;
                        }
                        size--;
                    }
                    if(max<size){
                        max=size;
                    }
                }
            }    
        }
        
        return max*max;
    }
};