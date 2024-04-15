class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        unordered_map<int,int> start;
        for(int i=0;i<n+1;i++){
            for(int j=max(0,i-ranges[i]);j<min(i+ranges[i],n);j++){
                if((j+ranges[j]<=i+ranges[i] || i+ranges[i]==n) 
                && (j-ranges[j]>=i-ranges[i] || i-ranges[i]==0) && j!=i){
                    ranges[j]=0;
                }
            }
        }

        for(int i=0;i<n+1;i++){
            if(ranges[i]!=0){
                start[max(0,i-ranges[i])]=i;
                printf("%d,%d\n",max(0,i-ranges[i]),start[max(0,i-ranges[i])]);
            }
        }
        int i=0,j=-1,count=0;
        while(true){
            
            while(start.find(i)==start.end()){
                if(i==0 || i==j){
                    return -1;
                }
                i--;
            }
            if(i==j){
                return -1;
            }
            j=i;
            i=min(start[i]+ranges[start[i]],n);
            count++;
            if(i==n){
                return count;
            }                
        }
        return count;
    }
};