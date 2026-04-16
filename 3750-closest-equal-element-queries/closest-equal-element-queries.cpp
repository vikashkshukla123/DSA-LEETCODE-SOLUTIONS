class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i];
            int ele = nums[idx];

            if (mp[ele].size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto &vec = mp[ele];

            int pos = lower_bound(vec.begin(), vec.end(), idx) - vec.begin();

            int m = vec.size();

            // next index (circular)
            int next = vec[(pos + 1) % m];

            // previous index (circular)
            int prev = vec[(pos - 1 + m) % m];

            // circular distance
            int d1 = min(abs(idx - next), n - abs(idx - next));
            int d2 = min(abs(idx - prev), n - abs(idx - prev));

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};