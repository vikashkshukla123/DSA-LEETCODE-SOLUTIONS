class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);
        }
        int ele = 1;
        while(true){
            if(st.find(ele) == st.end()){
                return ele;
                break;
            }
            ele++;

        }

        
        
    }
};