class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev(n,0);
        vector<int>next(n,0);
        prev[0] = nums[0];
        next[n-1] = nums[n-1];
        for(int i = 1; i<n; i++){
            prev[i] = max(nums[i],prev[i-1]);
        }

        for(int i = n-2; i>=0; i--){
            next[i] = max(nums[i],next[i+1]);
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(i == 0 || i == n-1){
                ans.push_back(nums[i]);
                continue;
            }

            if(prev[i] == nums[i] && nums[i] != prev[i-1]){
                ans.push_back(nums[i]);
                continue;
            }
            
             if(next[i] == nums[i] && nums[i] != next[i+1]){
                ans.push_back(nums[i]);
                continue;
            }
                
            
        }
        return ans;
    }
};