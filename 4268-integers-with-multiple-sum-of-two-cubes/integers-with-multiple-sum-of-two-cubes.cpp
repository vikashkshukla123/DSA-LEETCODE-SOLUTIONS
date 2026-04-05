class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long, int>mp;
        vector<int>ans;
        long long i = 1;
        while(i < n){
            long long j = i;
            long long cube_i = pow(i,3);
            if(cube_i > n) break;
            while(j < n){
                long long cube_j = pow(j,3);
                if(cube_j > n) break;
                long long cube = pow(i,3) + pow(j,3);
                
                if(cube > n){
                    break;

                }
                mp[cube]++;
                j++;

            }
            i++;
        }
        for(auto &[val, freq] : mp){
            long long num = val;
            long long f = freq;
            if(freq >= 2){
                ans.push_back(num);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};