class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int num = time[i];

            int val = num % 60;

            if(mp.find((60-val) % 60) != mp.end()){
                ans += mp[(60-val) % 60];
            }

            mp[val]++;
        }
return ans;

        
    }
};