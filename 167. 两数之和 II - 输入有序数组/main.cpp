class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        for(int i=0;i<numbers.size();){
            int start=i+1,end=numbers.size()-1;
            int tar=target-numbers[i];
            while(start<=end){
                int j=(end+start)/2;
                if(numbers[j]==tar){
                    vector<int> a={i+1,j+1};
                    return a;
                }else if(numbers[j]>tar){
                    end=j-1;
                }else{
                    start=j+1;
                }
            }


            int temp=numbers[i];
            while(i<numbers.size() && numbers[i]==temp){
                i++;
            }
        }
        vector<int> a={0,0};
        return a;
    }
};