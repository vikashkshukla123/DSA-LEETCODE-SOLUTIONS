class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        while(n != 0){
            int val = n % 10;
            mp[val]++;
            n = n / 10;
        }
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int val = it->first;
            int freq = it->second;

            ans += (val * freq);
        }
        return ans;
    }
};