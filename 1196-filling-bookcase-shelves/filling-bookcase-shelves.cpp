class Solution {
public:
int original_width;
int solve(int idx, int remaining_width, int max_height, vector<vector<int>>&books,vector<vector<int>>&dp){
    if(idx >= books.size()) return max_height;
    if(dp[idx][remaining_width] != -1){
        return dp[idx][remaining_width];
    }

    int take = 1e9;
    int skip = 1e9;
    if(books[idx][0] <= remaining_width){
        take = solve(idx + 1, remaining_width - books[idx][0], max(max_height,books[idx][1]), books,dp);
    }
      skip = max_height + solve(idx + 1, original_width - books[idx][0], books[idx][1], books,dp);

    return dp[idx][remaining_width]=  min(take,skip);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        original_width = shelfWidth;
        vector<vector<int>>dp(1002,vector<int>(1002,-1));
        return solve(0,shelfWidth,0,books,dp);
    }
};