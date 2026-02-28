class Solution {
    int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        string ans = "";
        for(int i = 1; i<=n; i++){
            string s = bitset<32>(i).to_string();
             s = s.substr(s.find('1'));  

            ans += s;

            
    }

    long long val = 0;

    for (char c : ans) {
            val = (val * 2 + (c - '0')) % mod;
        }

        

        

        return val;
    }
};