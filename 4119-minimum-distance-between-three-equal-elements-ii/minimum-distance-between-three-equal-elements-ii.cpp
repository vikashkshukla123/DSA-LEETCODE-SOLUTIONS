class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &p : mp) {
            vector<int> &a = p.second;
            int s = a.size();
            if (s < 3) continue;
            for (int i = 0; i + 2 < s; ++i) {
                ans = min(ans, 2 * (a[i+2] - a[i]));
            }


           
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
