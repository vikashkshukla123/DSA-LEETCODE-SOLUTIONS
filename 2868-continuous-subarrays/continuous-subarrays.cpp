class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        long long ans = 0;
        int left = 0;
        int right = 0;
        int mini = -1;
        int maxi = -1;
        while(right < n){
            mp[nums[right]]++;
            while(left < n && abs(mp.rbegin()->first - mp.begin()->first) > 2){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
          
          if(abs(mp.rbegin()->first - mp.begin()->first) <= 2){
              ans += 1LL * (right - left + 1);
          }
          right++;

        }
        return ans;
    }
};