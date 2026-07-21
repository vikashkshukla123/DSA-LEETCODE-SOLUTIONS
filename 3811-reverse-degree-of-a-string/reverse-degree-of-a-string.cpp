class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        int starting = 26;
        for(char ch = 'a'; ch <= 'z'; ch++){
            mp[ch] = starting;
            starting--;

        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int val = mp[s[i]];
            int result = val * (i + 1);
            ans += result;
        }
        return ans;
        
    }
};