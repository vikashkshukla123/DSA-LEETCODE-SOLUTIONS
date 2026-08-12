class Solution {
public:
int n;
int dp[100005][26];
string w;
int solve(int idx, char previous){
    if(idx >= n) return 0;
    int prevIdx = previous - 'a';
    if(dp[idx][prevIdx] != -1){
        return dp[idx][prevIdx];
    }
    int ans = INT_MAX;
    char currChar = w[idx];
    if(abs(currChar - previous) <= 1){
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(abs(ch - previous) <= 1) continue;
            ans = min(ans, 1 + solve(idx + 1, ch));
        }
    }else{
        ans = solve(idx + 1, currChar);
    }
    return dp[idx][prevIdx] = ans;
}
    int removeAlmostEqualCharacters(string word) {
        w = word;
        n = word.length();
        if(n <= 1) return 0;
        char previous = word[0];
        memset(dp, -1, sizeof(dp));
        return solve(1,previous);
        
    }
};