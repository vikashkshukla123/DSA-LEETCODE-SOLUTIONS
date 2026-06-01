class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int ans = 0 ;
        sort(cost.begin(),cost.end());
        int totalCost = 0;
        for(int i = 0; i < n; i++){
            totalCost += cost[i];
        }
        int cnt = 0;
        int costRemoved = 0;
        for(int i = n-1; i>=0; i--){
            cnt++;
            if((cnt % 3 == 0) && (cnt != 0)){
                costRemoved += cost[i];
            }
        }
        return totalCost - costRemoved;
    }
};