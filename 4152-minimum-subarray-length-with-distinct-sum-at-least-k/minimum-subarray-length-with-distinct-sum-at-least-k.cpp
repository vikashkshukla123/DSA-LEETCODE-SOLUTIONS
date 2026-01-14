class Solution {
public:
int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 1e9;
        unordered_map<int,int>mp;
        int sum = 0;
        while(right < n){
            mp[nums[right]]++;

           if(mp[nums[right]] == 1){
               sum += nums[right];
           }
           while(left < n && sum >= k){
               ans = min(ans, right - left + 1);

                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                    sum -= nums[left];
                }
                

                left ++;


                
            
            }
            

            

            right++;

        }
        return ans == 1e9 ? -1 : ans;
    }
};