class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();

        vector<long long>taskSum(n,0);
        taskSum[0] = 1LL *tasks[0];
        for(int i = 1; i < n; i++){
            taskSum[i] = 1LL * tasks[i] + taskSum[i-1];
        }
        long long workDoneTillNow = 0;
        int currentIdx = 0;
        vector<int>ans;
        for(int i = 0; i < m; i++){
            int time = shifts[i];

            int idx = lower_bound(begin(taskSum) + currentIdx ,end(taskSum),1LL * time + workDoneTillNow) - begin(taskSum);

            if(idx == n){
                ans.push_back(0);
                workDoneTillNow = 0;
                currentIdx = 0;

            }else if(taskSum[idx] ==  workDoneTillNow + shifts[i]){
                ans.push_back(n - (idx + 1));
                workDoneTillNow = taskSum[idx];
                currentIdx = idx + 1;

                if(currentIdx == n){
                    currentIdx = 0;
                    workDoneTillNow = 0;
                }
            }else if(taskSum[idx] > workDoneTillNow + shifts[i]){
                ans.push_back(n - idx);
                workDoneTillNow = workDoneTillNow + shifts[i];
                currentIdx = idx;
            }
        }

        return ans;
    }
};