class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int maxVal = -1e9;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
            st.insert(nums[i]);
            }else{
            maxVal = max(maxVal, nums[i]);
            }
        }
        for(int ele : st){
            ans += ele;
        }
        if(ans == 0) return maxVal;
        else return ans; 
    }
};