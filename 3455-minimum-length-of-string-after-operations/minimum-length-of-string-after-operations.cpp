class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }

        int cnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            char ch = it->first;
            int freq = it->second;

            if(freq >= 3){
                if(freq % 2 == 1){
                cnt += mp[ch] - 1;
                }else{
                    cnt += mp[ch] - 2;
                }
            }
        }

        return n - cnt;
    }
};