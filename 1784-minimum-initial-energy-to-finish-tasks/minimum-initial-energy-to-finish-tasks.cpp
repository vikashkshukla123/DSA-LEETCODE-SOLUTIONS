class Solution {
public:
bool isPossible(vector<vector<int>>&tasks, int mid){
     auto lambda = [](vector<int>&task1, vector<int>&task2){
        int energy1 = task1[1] - task1[0];
        int energy2 = task2[1] - task2[0];

        return energy1 > energy2;

    };
    sort(tasks.begin(),tasks.end(),lambda);
    int n = tasks.size();
    int energyPresent = mid;
    for(int i = 0; i < n; i++){
        int actual = tasks[i][0];
        int minimum = tasks[i][1];

        if(minimum > energyPresent){
            return false;
        }

        energyPresent -= actual;
    }
    return true;
   
}
    int minimumEffort(vector<vector<int>>& tasks) {
        int low = 0;
        int high = 1e9;
        int mid;
        int ans = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            if(isPossible(tasks,mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};