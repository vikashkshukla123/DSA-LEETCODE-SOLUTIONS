class Solution {
public:
int ans = 0;
void computePallindrome(string &s, vector<vector<bool>>&isPallindrome){
    int n = s.length();
    for(int L = 1; L <= n; L++){
        for(int i = 0; i + L - 1 < n; i++){
            int j = i + L - 1;
            if(i == j){
                isPallindrome[i][j] = true;
                ans++;
            }else if(i + 1 == j){
                isPallindrome[i][j] = (s[i] == s[j]);
                if(isPallindrome[i][j]){
                ans++;
                }
            }else{
                isPallindrome[i][j] = (s[i] == s[j] && isPallindrome[i+1][j-1]);
                if(isPallindrome[i][j]){
                    ans++;
                }
            }
        }
    }
    return;
}
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>isPallindrome(n+1,vector<bool>(n,false));
        computePallindrome(s,isPallindrome);
        return ans;
        
        
    }
};