class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            int m = s.length();
            for(int i = 0; i < m; i++){
                int val = s[i] - '0';
                ans.push_back(val);
            }
        }
        return ans;
        
    }
};