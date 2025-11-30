class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            int mod = sum % k;
            if(mod < 0) mod = mod + k;
            if(mp.find(mod) != mp.end()){
                res += mp[mod];
            }
            mp[mod]++;
        }
        return res;
    }
};