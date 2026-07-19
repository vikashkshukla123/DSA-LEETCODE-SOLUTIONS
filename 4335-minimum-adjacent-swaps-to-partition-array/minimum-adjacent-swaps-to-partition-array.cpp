class Solution {
public:
int mod = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int>converted;
        for(int i = 0; i < n; i++){
            if(nums[i] >= a && nums[i] <= b){
                converted.push_back(1);

            }
            else if(nums[i] < a){
                converted.push_back(0);
            }else if(nums[i] > b){
                converted.push_back(2);
            }
                
        }

        unordered_map<int,int>mp;
        mp[0] = 0;
        mp[1] = 0;
        mp[2] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
           int val = converted[i];
           if(val == 2){
            mp[2] = (mp[2] + 1) % mod;
           }else if(val == 0){
            ans  = (ans + mp[1]) % mod;
            ans  = (ans + mp[2]) % mod;

            mp[0] = (mp[0] + 1) % mod;
           }else {
            ans  = (ans + mp[2]) % mod;
            mp[1] = (mp[1] + 1) % mod;
           }
        }

        return ans;
    }
};