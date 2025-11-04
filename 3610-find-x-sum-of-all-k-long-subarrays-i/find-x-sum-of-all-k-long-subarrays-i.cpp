class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int ans_vec = n - k + 1;
        vector<int> ans(ans_vec, 0);
        unordered_map<int, int> mp;

        // Initialize frequency map for the first window
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        for (int i = 0; i < ans_vec; i++) {
            // build heap for current window
            priority_queue<pair<int,int>> pq;
            for (auto &it : mp) {
                pq.push({it.second, it.first});
            }

            int s = 0;
            int cnt = x;
            while (cnt-- && !pq.empty()) {
                s += pq.top().first * pq.top().second;
                pq.pop();
            }
            ans[i] = s;

            // Slide the window:
            if (i + k < n) {
                // remove leftmost element
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                // add new element entering window
                mp[nums[i + k]]++;
            }
        }

        return ans;
    }
};
