class Solution {
public:
    const long long MOD = 1e9 + 7; 
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        unordered_map<long long, long long> mp;
        vector<long long> prevFreq(n, 0), nextFreq(n, 0);

        mp[nums[0]]++;
        for(int i = 1; i < n; ++i){
            long long val = nums[i];
            long long to_find = val * 2LL;
            auto it = mp.find(to_find);
            if(it != mp.end()){
                prevFreq[i] = it->second;
            }
            mp[val]++;
        }

  
        mp.clear();
        mp[nums[n-1]]++;
        for(int i = n - 2; i >= 0; --i){
            long long val = nums[i];
            long long to_find = val * 2LL;
            auto it = mp.find(to_find);
            if(it != mp.end()){
                nextFreq[i] = it->second;
            }
            mp[val]++;
        }

        long long ans = 0;
        for(int i = 0; i < n; ++i){
            if(prevFreq[i] != 0 && nextFreq[i] != 0){
    
                ans = (ans + (prevFreq[i] * nextFreq[i]) % MOD) % MOD;
            }
        }

        return (int)ans;
    }
};
