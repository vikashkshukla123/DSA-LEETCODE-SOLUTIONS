class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n =  nums.size();
        if(n == 1) return nums[0]+1;
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        int curr_sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1){
                while(st.find(curr_sum) != st.end()){
                    curr_sum = curr_sum + 1;
                }
                ans = curr_sum;
                break;
            }else{
                curr_sum += nums[i];
            }
        }
        if(ans == 0) return curr_sum;
        return ans;
    }
};