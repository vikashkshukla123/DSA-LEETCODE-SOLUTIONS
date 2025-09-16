class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        for(int i = 0; i<n; i++){
            st.push(nums[i]);

            while(st.size() >= 2){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int g = gcd(a,b);
                if(g > 1){
                     long l = (long)a / g * b; 
                     st.push((int)l);
                }else{
                    st.push(a);
                    st.push(b);
                    break;
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};