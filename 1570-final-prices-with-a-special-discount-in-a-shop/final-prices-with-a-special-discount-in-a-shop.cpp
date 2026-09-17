class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int price = prices[i];
            bool found = false;
            for(int j = i+1; j < n; j++){
                if(prices[j] <= price){
                    found = true;
                    ans.push_back(price - prices[j]);
                    break;
                }
            }
            if(found == false){
                ans.push_back(price);
            }
        
        }
return ans;
        
    }
};