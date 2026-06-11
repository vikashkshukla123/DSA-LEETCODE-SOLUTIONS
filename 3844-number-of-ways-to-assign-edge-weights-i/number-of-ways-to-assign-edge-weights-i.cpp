class Solution {
public:
    static const int mod = 1e9 + 7;

    long long modPow(long long a, long long b) {
        if (b == 0) return 1;

        long long res = modPow(a, b / 2);
        res = (res * res) % mod;

        if (b & 1) {
            res = (res * a) % mod;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        unordered_map<int, vector<int>> mp;

        // Build undirected tree
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        queue<pair<int, long long>> q;
        vector<int> vis(n + 1, 0);

        q.push({1, 0});
        vis[1] = 1;

        long long maxLevel = 0;

        while (!q.empty()) {
            auto [node, lev] = q.front();
            q.pop();

            maxLevel = max(maxLevel, lev);

            for (int nxt : mp[node]) {
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push({nxt, lev + 1});
                }
            }
        }

        if (maxLevel == 0) return 1;

        return (int)modPow(2, maxLevel - 1);
    }
};