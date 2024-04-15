class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int* nums=new int[numCourses];

        for(int i=0;i<numCourses;i++){
            nums[i]=0;
        }

        vector<vector<int>> map(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            nums[prerequisites[i][1]]++;
            map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        bool t=true;
        while(t){
            t=false;
            for(int i=0;i<numCourses;i++){
                if(nums[i]==0){
                    nums[i]=-1;
                    for(int j:map[i]){
                        nums[j]--;
                    }
                    t=true;
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(nums[i]!=-1){
                return false;
            }
        }
        return true;
    }
};