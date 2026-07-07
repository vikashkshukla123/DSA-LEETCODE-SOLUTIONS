class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>even(n,0);
        vector<int>odd(n,0);

        if(nums[0] % 2 == 0){
            even[0] = 1;
        }

        if(nums[0] % 2 == 1){
            odd[0] = 1;
        }

        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == 0){
                even[i] = 1 + even[i-1];
            }else{
                even[i] = even[i-1];
            }
        }

        for(int i = 1; i < n; i++){
            if(nums[i] % 2 == 1){
                odd[i] = 1 + odd[i-1];
            }else{
                odd[i] = odd[i-1];
            }
        }

        int curr_xor = 0;
        unordered_map<int,unordered_map<int,int>>mp;
        mp[0][0] = -1;

        int ans = 0;
        for(int i = 0; i < n; i++){
            curr_xor ^= nums[i];
            int diff = even[i] - odd[i];

            if(mp.find(curr_xor) != mp.end()){
                if(mp[curr_xor].find(diff) != mp[curr_xor].end()){
                    ans = max(ans, i - mp[curr_xor][diff]);
                }else{
                    mp[curr_xor][diff] = i;
                }
            }else{
                mp[curr_xor][diff] = i;
            }

            
            
        }
        
return ans;


        
    }
};