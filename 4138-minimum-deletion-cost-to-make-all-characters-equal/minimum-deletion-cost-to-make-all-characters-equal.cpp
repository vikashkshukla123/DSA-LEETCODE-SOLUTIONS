class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = cost.size();
        unordered_map<char,long long> mp;
        long long max_freq = 0;   // FIX: use long long
        long long total = 0;

        for(int i = 0; i<n; i++){
            // FIX: simplify update
            mp[s[i]] += cost[i];

            total += cost[i];

            // FIX: compare with long long
            if(mp[s[i]] > max_freq){
                max_freq = mp[s[i]];
            }
        }

        // FIX: no need for size check
        return total - max_freq;
    }
};