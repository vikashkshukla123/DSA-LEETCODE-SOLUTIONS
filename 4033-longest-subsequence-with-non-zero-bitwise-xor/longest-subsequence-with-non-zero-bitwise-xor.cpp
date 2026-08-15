class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int whole_xor = 0;
        for(int i = 0; i < n; i++){
            whole_xor ^= nums[i];
            mp[nums[i]]++;
        }

        if(mp.size() == 1 && mp.begin()->first == 0){
            return 0;
        };

        if(whole_xor == 0){
            return n-1;
        }else{
            return n;
        }
        
    }
};