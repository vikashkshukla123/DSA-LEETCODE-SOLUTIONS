class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,long long>mp;
        int n = words.size();

        for(int i = 0; i<n; i++){
            string step = "";
            string s = words[i];
            for(int j = 0; j<s.length() - 1; j++){
                long long steps = 0;
                steps = (s[j] - s[j+1] + 26) % 26;
                step += to_string(steps);
                step += "#";

            }
            mp[step]++;
        }

        long long ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            long long same = it->second;
            
            ans += same*(same-1)/2;
            

        }

        return ans;

        
    }
};