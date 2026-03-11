class Solution {
public:
void solve(int idx, int target, vector<vector<int>>&ans, vector<int>&ds,vector<int>&candidates){
   
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        


    for(int i = idx; i < candidates.size(); i++){
        if(i > idx && candidates[i] == candidates[i-1]){
            continue;
        }

        if(candidates[i] > target) break;
        ds.push_back(candidates[i]);
        solve(i + 1, target - candidates[i], ans, ds, candidates);
        ds.pop_back();

    }


}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0, target,ans,ds,candidates);
        return ans;
    


    }
};