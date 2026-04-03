class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int groups = n / k;
        if( k > n) return false;
        if(n % k != 0) return false;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto &[val,freq] : mp){
            if(freq > groups){
                return false;
            }
        }

        return true;
    }
};