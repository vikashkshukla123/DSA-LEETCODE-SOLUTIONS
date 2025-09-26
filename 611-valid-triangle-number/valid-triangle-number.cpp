class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            for(int j = i+1; j<n-1; j++){
                int a = nums[i];
                int b = nums[j];
                
                int idx  = lower_bound(nums.begin(),nums.end(),a+b) - nums.begin();
                if(idx >= j+1){
                    ans += (idx -  j - 1);
                }
                
                

                
            }
        }
        return ans;
        
    }
};