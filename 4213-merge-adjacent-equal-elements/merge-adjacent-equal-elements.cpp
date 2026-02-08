class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        stack<long long>st;
        for(int i = 0; i<n; i++){
            if(st.empty() || st.top() != nums[i]){
                st.push(nums[i]);
            }else{
                long long num = nums[i];

                while(!st.empty() && st.top() == num){
                    long long a = st.top();
                    st.pop();
                    num = a + a;
                }
                st.push(num);
                
            }
        }

        int k = st.size();
        vector<long long>ans(k,0);
        int i = k-1;
        while(!st.empty()){
            long long a = st.top();
            ans[i] = a;
            st.pop();
            i--;
        }
        return ans;


    }
};