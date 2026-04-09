class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = capacity[0];

        for(int i = 1; i<n; i++){
            prefixSum[i] = capacity[i] + prefixSum[i-1];
        }

        long long ans = 0;
        map<pair<int,long long>,long long>mp;
        for(int j = 0; j<n; j++){
            long long val = capacity[j];
            long long sum = prefixSum[j];

             if(j >= 2){
                int i = j-2;

                long long x = capacity[i];
                long long prefix = i > 0 ? prefixSum[i-1] : 0;

                mp[{x, prefix + 3 * x}]++;

             }

             auto it = mp.find({val, sum});

             if(it != mp.end()) ans += it->second;
        }

        return ans;
    }
};