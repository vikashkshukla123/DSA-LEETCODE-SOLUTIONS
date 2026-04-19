class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxFrom(n,0);
        vector<int>minFrom(n,0);

        maxFrom[0] = nums[0];
        for(int i = 1; i<n; i++){
            maxFrom[i] = max(nums[i], maxFrom[i-1]);
        }
        minFrom[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            minFrom[i] = min(nums[i], minFrom[i+1]);
        }

        int ans = -1;
        for(int i = 0; i<n; i++){
            int score = maxFrom[i] - minFrom[i];
            if(score <= k){
                ans = i;
                break;
            }

        }

        return ans;
        
    }
};