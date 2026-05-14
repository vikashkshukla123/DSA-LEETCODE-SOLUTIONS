class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int cumSum = 0;
        for(int i = 0; i < n; i++){
            cumSum += nums[i];

            int remaining = cumSum - k;
            if(mp.find(remaining) != mp.end()){
                ans += mp[remaining];
            }

            mp[cumSum]++;
        }
        return ans;
    }
};