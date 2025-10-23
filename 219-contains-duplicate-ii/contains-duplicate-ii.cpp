class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        int left = 0;
        int right = 0;
        unordered_map<int,int>mp;
        while(right < n){
            mp[nums[right]]++;

            while(left < n && abs(left - right) > k){
                mp[nums[left]]--;
                left ++;
                
            }
            if(mp[nums[right]] >= 2){
                    return true;
            }
                right++;
            
        }
        return false;

        
    }
};