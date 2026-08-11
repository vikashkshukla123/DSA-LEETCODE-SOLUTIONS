class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<int,vector<int>>adj;
        int n = parent.size();
        for(int i = 1; i < n; i++){
            int node = i;
            int parents = parent[i];
            adj[parents].push_back(node);
        }
        vector<int>dept(n,0);
        queue<pair<int,int>>q1;
        vector<bool>visited1(n,false);
        visited1[0] = true;
        q1.push({0,1});
        while(!q1.empty()){
            auto it = q1.front();
            q1.pop();
            int node = it.first;
            int d = it.second;

            dept[node] = d;
            for(auto& ngbr : adj[node]){
                if(!visited1[ngbr]){
                    q1.push({ngbr, d + 1});
                    visited1[ngbr] = true;
                }
            }
        }
        int h = 0;
        for(int i = 0; i < n; i++){
            h = max(h,dept[i]);
        }


        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long res = 1LL * nums[i] * (1LL * h - 1LL * dept[i] + 1);
            ans += res;
        }

return ans;



    }
};