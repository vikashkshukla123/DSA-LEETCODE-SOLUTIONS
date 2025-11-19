class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        int ans = original;
        while(true){
            if(st.find(original) != st.end()){
                original = 2*original;
                ans = original;
            }else{
                break;
            }
        }
        
        return ans;
    }
};