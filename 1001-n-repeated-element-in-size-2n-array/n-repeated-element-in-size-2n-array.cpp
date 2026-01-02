class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int twonsize = nums.size();
        unordered_set<int>st;
        int ans;
        for(int i = 0; i<twonsize; i++){
            if(!st.empty() && st.find(nums[i]) != st.end()){
                ans = nums[i];
                break;
            }
            st.insert(nums[i]);
        }
        return ans;
    }
};