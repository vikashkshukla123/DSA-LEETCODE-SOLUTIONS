class Solution {
public:

int solve(int i, int j, vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
    int n = nums1.size();
    int m = nums2.size();


    if(i >= n || j >= m){
        return -1e9;

    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int case1 = nums1[i] * nums2[j] + max(0,solve(i+1,j+1,nums1,nums2,dp));

    int cas2 = solve(i, j+1, nums1,nums2,dp);

    int case3 = solve(i+1,j, nums1,nums2,dp);


    return dp[i][j] =  max({case1,cas2,case3});
}



    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));


        return solve(0,0,nums1,nums2,dp);
        
    }
};