class Solution {
public:
    string findValidPair(string s) {
        int n = s.length();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int val = s[i] - '0';
            mp[val]++;
        }
        string ans = "";
        for(int i = 0; i < n-1; i++){
            int val1 = s[i] - '0';
            int val2 = s[i+1] - '0';
            if(val1 != val2 && mp[val1] == val1 && mp[val2] == val2){
                ans += to_string(val1);
                ans += to_string(val2);
                break;
            }
        }
        return ans;
    }
};