class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int left = 0, right = 0;
        multiset<int> st;
        vector<int> ans;

        while (right < n) {
            // Shrink window if too big
            while (right - left + 1 > k) {
                if (nums[left] < 0) {
                    auto it = st.find(nums[left]);
                    if (it != st.end()) st.erase(it);
                }
                left++;
            }

            // Add current if negative
            if (nums[right] < 0) st.insert(nums[right]);

            // If valid window, process beauty
            if (right - left + 1 == k) {
                if ((int)st.size() < x) {
                    ans.push_back(0);
                } else {
                    int s = 0;
                    for (auto it = st.begin(); it != st.end(); it++) {
                        s++;
                        if (s == x) {
                            ans.push_back(*it);
                            break;
                        }
                    }
                }
            }

            right++;
        }

        return ans;
    }
};
