class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = nums[n-1];

        int cnt = 0;
        for(int i = 0; i<n-1; i++){
            cnt += maxi - nums[i];
        }

        return cnt;

        
    }
};