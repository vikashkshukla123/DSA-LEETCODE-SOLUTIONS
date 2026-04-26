class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        unordered_set<int>st;
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            mp[u].push_back(v);
            st.insert(v);
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};