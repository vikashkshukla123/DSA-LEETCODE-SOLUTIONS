class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        long long ans = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && st.top() < nums[i]){
                if(st.size() == 1){
                    st.pop();

                }else{
                    ans ++;
                    st.pop();
                }
                
            }
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                st.push(nums[i]);
            }
        }
        return ans;
        
    }
};