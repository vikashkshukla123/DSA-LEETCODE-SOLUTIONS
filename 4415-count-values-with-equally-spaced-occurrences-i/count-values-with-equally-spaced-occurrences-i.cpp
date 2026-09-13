class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int val = it->first;
            vector<int>&idx = it->second;
            if(idx.size() != 3){
                continue;
            }
            if(idx[1] - idx[0] == idx[2] - idx[1]){
                ans++;
            }
        }
        return ans;
    }
};