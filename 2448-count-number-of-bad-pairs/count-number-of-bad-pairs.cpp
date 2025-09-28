class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long good = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            int diff = i - nums[i];
            if(mp.find(diff) != mp.end()){
                good += mp[diff];
            }
            mp[diff]++;
        }
        long long total = n*(n-1)/2;
        long long ans = total - good;

        return ans;
        
    }
};