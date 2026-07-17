class Solution {
public:
int T;
int globalCost = INT_MAX;
void solve(vector<int>&toppingCosts, int idx, int cost){
    int n = toppingCosts.size();

    
    if(abs(T - cost) < abs(T - globalCost)){
        globalCost = cost;
    }else if(abs(T - cost) == abs(T - globalCost)){
        globalCost = min(globalCost, cost);
        
    }

    if(idx >= n) return;


    solve(toppingCosts, idx + 1, cost);
    solve(toppingCosts, idx + 1, cost + toppingCosts[idx]);
    solve(toppingCosts, idx + 1, cost + 2*toppingCosts[idx]);

    return;
}
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        T = target;
        for(int i = 0; i < baseCosts.size(); i++){
            solve(toppingCosts, 0, baseCosts[i]);
        }
        return globalCost;
    }
};