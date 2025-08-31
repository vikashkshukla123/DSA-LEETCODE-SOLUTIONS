class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_freq = -1e9;
        int ans = 0;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i  = 0; i<n; i++){
            mp[nums[i]]++;
            max_freq = max(max_freq,mp[nums[i]]);
        }
        for(auto i : mp){
            if(i.second == max_freq){
                ans += i.second;
            }
        }
return ans;

        
        
    }
};