class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr_min = prices[0];
        int ans = 0;
        for(int i = 1; i<n; i++){
            ans = max(ans , prices[i] - curr_min);
            curr_min = min(curr_min, prices[i]);
        }
        
        return ans;
    }
};