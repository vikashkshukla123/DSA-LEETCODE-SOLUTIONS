class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long>profit(n);
        long long original_profit = 0;
        for(int i = 0; i<n; i++){
            original_profit += prices[i] * strategy[i];
            profit[i] = prices[i] * strategy[i];
        }

        long long original_window = 0;
        long long modified_window = 0;

        long long maxi = -1e18;

        int left = 0;
        int right = 0;

        while(right < n){
            original_window += profit[right];

            if(right - left + 1 > k/2){
                modified_window += prices[right];
            }

            while(left < n && right - left + 1 > k){
                original_window -= profit[left];
                modified_window -= prices[left + k/2] ;
                left++;
            }

            if(right - left + 1 == k){
                maxi = max(maxi, modified_window - original_window);

            }

            right++;
        }
        

        if(maxi < 0){
            return original_profit;
        }

        return original_profit + maxi;
    }
};