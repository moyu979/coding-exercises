class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> a;
        if(finalSum%2==1){
            return a;
        }
        else{
            finalSum/=2;
            for(int i=1;;i++){
                if(finalSum>=i){
                    finalSum-=i;
                    a.push_back(i*2);
                }else{
                    finalSum*=2;
                    finalSum+=a.back();
                    a.pop_back();
                    a.push_back(finalSum);
                    break;
                }
                
            }
        }
        return a;
    }
};