class Solution {
public:
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        long int n=classes.size();
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            long int pass=classes[i][0],total=classes[i][1];
            double passRate=double(total-pass)/double(total*(total+1));
            pq.push(make_pair(passRate,i));
        }
        for(int i=0;i<extraStudents;i++){    
            pair<double,int> c=pq.top();
            pq.pop();
            classes[c.second][0]++;
            classes[c.second][1]++;
            long int pass=classes[c.second][0],total=classes[c.second][1];
            double passRate=double(total-pass)/double(total*(total+1));
            pq.push(make_pair(passRate,c.second));
        }
        double rate=0;
        for(int i=0;i<n;i++){
            long int pass=classes[i][0],total=classes[i][1];
            rate+=double(pass)/double(total);
        }
        rate=rate/n;
        return rate;
    }
};