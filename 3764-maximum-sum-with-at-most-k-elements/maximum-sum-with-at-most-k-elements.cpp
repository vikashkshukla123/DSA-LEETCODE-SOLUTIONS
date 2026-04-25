class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        int j = 0;
        priority_queue<long long>pq;
        for(int i = 0; i<n; i++){
            vector<int>&vec = grid[i];
            sort(vec.rbegin(),vec.rend());

            int ele = limits[j];
            for(int k = 0; k<ele; k++){
                pq.push(vec[k]);

            }
            j++;

        }
        if(pq.empty()) return 0;
        while(!pq.empty() && k != 0){
            sum += pq.top();
            pq.pop();
            k--;
        }

        return sum;
        
    }
};