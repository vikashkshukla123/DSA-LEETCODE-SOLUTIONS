class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = 0;
        int closest = INT_MAX;
        unordered_set<int>st;
        for(int i = 0; i < nums.size(); i++){
            int dist = abs(nums[i] - 0);
            st.insert(nums[i]);
            if(dist < closest){
                ans = nums[i];
                closest = dist;
            }else if(dist == closest ){
                ans = max(closest, nums[i]);
            }
        }
        if(st.find(ans) != st.end()){
            return ans;
        }
        return (-1*ans);
    }
};