class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int ans = 0;
        int idx = 0;
        sort(costs.begin(),costs.end());
        while(coins != 0 && idx < n){
            if(costs[idx] <= coins){
                ans++;
                coins -= costs[idx];
                idx++;
            }else{
                break;
            }
        }
        return ans;
    }
};