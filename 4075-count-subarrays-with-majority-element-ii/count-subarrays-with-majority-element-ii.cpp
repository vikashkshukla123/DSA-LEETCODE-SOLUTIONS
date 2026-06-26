class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<long long , long long>mp;
        mp[0] = 1;
        long long cumSum = 0;
        long long validPoints = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                validPoints += mp[cumSum];
                cumSum += 1;
            }else{
                cumSum -= 1;
                validPoints -= mp[cumSum];
            }

            mp[cumSum]++;
            ans += validPoints;
        }
        return ans;
    }
};