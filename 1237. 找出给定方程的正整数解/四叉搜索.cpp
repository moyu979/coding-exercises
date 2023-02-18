/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    int z;
    vector<vector<int>> zeros;
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        this->z=z;
        judge(customfunction,1,1000,1,1000);
        return zeros;
    }
    void judge(CustomFunction& customfunction,int x1,int x2,int y1,int y2){
        int halfx=(x1+x2)/2;
        int halfy=(y1+y2)/2;
        int res=customfunction.f(halfx,halfy);
        if(y1>=y2 || x1>=x2){
            return ;
        }
        if(halfx==x1 && halfy==y1){
            if(res==z){
                zeros.push_back(vector<int>{halfx,halfy});
            }
            return;
        }
        else if(res>z){//2,3,4象限
            judge(customfunction,x1,halfx,y1,halfy);//     √|x
            judge(customfunction,x1,halfx,halfy,y2);//    --+--
            judge(customfunction,halfx,x2,y1,halfy);//     √|√
        }else if(res<z){//1，2,4象限
            judge(customfunction,x1,halfx,halfy,y2);//     √|√
            judge(customfunction,halfx,x2,halfy,y2);//    --+--
            judge(customfunction,halfx,x2,y1,halfy);//     x|√
        }
        else{//2，4象限
            zeros.push_back(vector<int>{halfx,halfy});
            judge(customfunction,x1,halfx,halfy+1,y2);
            judge(customfunction,halfx+1,x2,y1,halfy);
        }
    }
};