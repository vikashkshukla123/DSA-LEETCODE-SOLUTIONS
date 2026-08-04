class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int low = nums[0];
        int high = nums[n-1];
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        
        for(int i = low + 1; i < high; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};