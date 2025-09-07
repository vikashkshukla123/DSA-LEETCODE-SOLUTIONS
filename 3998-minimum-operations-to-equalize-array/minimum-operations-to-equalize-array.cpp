class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        if(st.size() == 1) return 0;
        return 1;
        
    }
};