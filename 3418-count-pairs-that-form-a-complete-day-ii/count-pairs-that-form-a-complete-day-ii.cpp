class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        long long ans = 0;
        unordered_map<long long,long long>mp;
        for(int i = 0; i<n; i++){
            long long val = hours[i];
            long long rem = val % 24;
            long long compliment = (24 - rem) % 24;

            if(mp.find(compliment) != mp.end()){
                ans += mp[compliment];
            }

            mp[rem]++;
        }
        return ans;
        
    }
};