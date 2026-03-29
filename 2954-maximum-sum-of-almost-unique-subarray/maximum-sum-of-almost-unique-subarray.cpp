class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        long long sum = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        unordered_map<int,int>mp;
        while(right < n){
            sum += nums[right];
            mp[nums[right]]++;


            while(left < n && (right - left + 1) > k){
                sum -= nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }


              if(right - left + 1 == k && mp.size() >= m){
                ans = max(ans, sum);
            }

            right ++;
        }

      

return ans;

        
    }
};