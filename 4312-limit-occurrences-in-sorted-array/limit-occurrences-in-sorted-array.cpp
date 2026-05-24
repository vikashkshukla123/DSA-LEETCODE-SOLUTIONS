class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        int idx = 0;
        while(idx < n){
            int ele = nums[idx];
            int freq = mp[ele];

            for(int i = 0; i < min(k,freq); i++){
                ans.push_back(ele);
            }
            idx += freq;

        }
        
        
        return ans;
    }
};