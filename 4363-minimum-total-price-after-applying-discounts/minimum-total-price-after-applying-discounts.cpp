class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());

        double ans = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            double price = ((double)prices[i] * (100.0 - (double)discounts[i]))/100.0;
            ans += price;
            i++;
            j++;
        }

        if(i < n){
            while(i < n){
                ans += prices[i];
                i++;
            }
        }
return ans;

        
    }
};