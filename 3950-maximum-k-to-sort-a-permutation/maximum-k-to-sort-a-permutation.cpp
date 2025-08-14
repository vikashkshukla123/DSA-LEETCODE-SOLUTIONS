class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int max_k = pow(2,ceil(log2(n))) - 1;
        int k = max_k;


        for(int i = 0; i<n; i++){
            if(nums[i] != i){
                k &= nums[i];
            }
        }
        return k == max_k ? 0 :k;
    }
};