class Solution {
public:
int solve(int idx, vector<int>&arr, int d,vector<int>&dp){
    int n = arr.size();
    if(idx < 0 || idx >= arr.size()){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }

    int ans = 0;
    int case1 = 0;
    int case2 = 0;
    for(int right_idx = idx + 1; right_idx <= min(n-1,idx + d); right_idx++){
        if(arr[right_idx] >= arr[idx]){
            break;
        }
        case1 = max(case1,solve(right_idx, arr,d,dp));
    }

    for(int left_idx = idx - 1; left_idx >= max(0,idx - d); left_idx--){
        if(arr[left_idx] >= arr[idx]){
            break;
        }

        case2 = max(case2,solve(left_idx, arr,d,dp));


    }

    dp[idx] = 1 + max(case1,case2);

    return dp[idx];






}
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int maxi = -1e9;
        vector<int>dp(n,-1);
        for(int i = 0; i < n; i++){
            int maxDistance = solve(i,arr,d,dp);
            maxi = max(maxi, maxDistance);
        }
        return maxi;
    }
};