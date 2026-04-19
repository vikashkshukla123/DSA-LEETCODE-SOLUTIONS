class Solution {
public:
int mod = 1e9 + 7;
   int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>next_smaller(n);
        vector<int>prev_smaller(n);
        vector<long long>prefixSum(n,0);
        stack<int>st1;
        stack<int>st2;
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        // calculating next_smaller_element
        st1.push(-1);
        for(int i = n-1; i>=0; i--){
            while(st1.top() != -1 && nums[st1.top()] >= nums[i]){
                st1.pop();
            }
            
            next_smaller[i] = st1.top();
            st1.push(i);
        }

        // calculating the prev_smaller_element
        st2.push(-1);
        for(int i = 0; i<n; i++){
            while(st2.top() != -1  && nums[st2.top()] >= nums[i]){
                st2.pop();
            }
            prev_smaller[i] = st2.top();
            st2.push(i);
        }

        long long ans = 0;

for(int i = 0; i < n; i++){
    long long minimum = nums[i];

    int l = prev_smaller[i] + 1;
    int r = (next_smaller[i] == -1 ? n - 1 : next_smaller[i] - 1);

    long long sum = (l == 0) ? prefixSum[r] : prefixSum[r] - prefixSum[l - 1];

    ans = max(ans, minimum * sum);
}

return ans % mod;

  
    

        
        
    }
};