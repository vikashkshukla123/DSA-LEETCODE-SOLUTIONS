class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int cnt = 0;
        int preSum = 0;
        mp[0] = 1;
        for(int i = 0; i<n; i++){
            preSum += nums[i];

            int rem = preSum - k;

            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
            }
            mp[preSum]++;
        }
        return cnt;

        
    }
};