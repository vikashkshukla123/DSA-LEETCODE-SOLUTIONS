class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>preMul(n,1);
        vector<int>suffMul(n,1);
        preMul[0] = nums[0];

        for(int i = 1; i<n; i++){
            preMul[i] = nums[i] * preMul[i-1];

        }
        suffMul[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            suffMul[i] = nums[i] * suffMul[i+1];
        }

        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(i == 0){
                ans.push_back(suffMul[i+1]);
            }else if(i == n-1){
                ans.push_back(preMul[i-1]);
            }else{
                ans.push_back(preMul[i-1] * suffMul[i+1]);
            }
        }

return ans;
        
    }
};