class Solution {
public:
int mod = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = n-1; i >= 0; i--){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
        }
        int ans = 1;
        int i = 0;
        int j = 0;
        j = max(0,mp[nums[0]]);

        while(i < n){
            if(i > j){
                ans = (2 * ans) % mod;
            }
            j = max(j,mp[nums[i]]);
            i++;

        }

        return ans;
    }
};