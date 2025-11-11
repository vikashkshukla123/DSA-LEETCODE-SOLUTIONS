class Solution {
public:
int f(int i, int zeros, int ones, vector<pair<int,int>>&p,int m, int n,vector<vector<vector<int>>>&dp){
    
    if(zeros > m || ones > n) return -1e9;
    if(i == p.size()) return 0;

    if(dp[i][zeros][ones] != -1) return dp[i][zeros][ones];

    int take = 1 + f(i+1, zeros + p[i].first, ones + p[i].second,p,m,n,dp);
    int nottake =  f(i+1, zeros, ones,p, m,n,dp);

    return dp[i][zeros][ones] = max(take, nottake);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<pair<int,int>>p;
        for(int i = 0; i<k; i++){
            string s = strs[i];
            int cnt1 = 0;
            int cnt0 = 0;
            for(int j = 0; j<s.length(); j++){
                if(s[j]  == '1'){
                    cnt1++;
                }else{
                    cnt0++;
                }
            }
            p.push_back({cnt0,cnt1});
        }
        vector<vector<vector<int>>>dp(k+1, vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        return f(0,0,0,p,m,n,dp);
        
    }
};