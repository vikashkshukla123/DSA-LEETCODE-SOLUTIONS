class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans = nums;
        sort(nums.begin(),nums.end());
        int idx1 = 0;
        while(idx1 < n){
            if(nums[idx1] != ans[idx1]){
                break;
            }else{
                idx1++;
            }
        }
        int idx2 = n-1;
        while(idx2 >= 0){
            if(nums[idx2] != ans[idx2]){
                break;
            }else{
                idx2--;
            }
        }
        return (idx1 > idx2) ? 0 : (idx2 - idx1 + 1);

      
        
    }
};