class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i<n; i++){
            int idx = (i + k)%n;
            ans += s[idx];
        }
        return ans;
    }
};