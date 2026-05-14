class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return false;
        }
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int maxi = nums[n-1];
        if(n != maxi + 1 || nums[0] != 1){
            return false;
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > 1 && it->first != maxi){
                return false;
            }

        }
        return true;
    }
};