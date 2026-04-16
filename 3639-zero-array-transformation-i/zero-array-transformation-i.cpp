class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        vector<int>diff(n,0);
        for(int i  = 0; i < queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int x = -1;

            diff[start] +=x;
            if(end + 1 < n){
                diff[end + 1] -= x;

            }
        }
        vector<int>res(n,0);
        int cumSum = 0;
        for(int i = 0; i<n; i++){
            cumSum += diff[i];
            res[i] = cumSum;

        }
        for(int i = 0; i<n; i++){
            if(res[i] = res[i] + nums[i]);
        }

        for(int i = 0; i<n; i++){
            if(res[i] > 0) return false;
        }

        return true;
    }
};