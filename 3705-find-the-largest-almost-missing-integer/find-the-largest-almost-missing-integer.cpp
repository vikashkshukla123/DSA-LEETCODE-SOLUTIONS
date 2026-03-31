class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i <= n - k; i++){
            unordered_set<int> st;

            // collect unique elements in this window
            for(int j = i; j < i + k; j++){
                st.insert(nums[j]);
            }

            // count each element once per window
            for(auto val : st){
                mp[val]++;
            }
        }

        int ans = -1;

        for(auto &[val, freq] : mp){
            if(freq == 1){
                ans = max(ans, val);
            }
        }

        return ans;
    }
};