class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(mp[nums[i]] % k == 0){
                ans += nums[i];
            }
        }
        return ans;
        
    }
};