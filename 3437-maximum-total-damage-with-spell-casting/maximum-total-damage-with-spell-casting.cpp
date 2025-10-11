class Solution {
public:
long long solve(int i, vector<int>&power, unordered_map<int,int>&mp, vector<long long int>&dp){
    int n = power.size();
    if(i >= n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    auto it = lower_bound(power.begin(),power.end(),power[i]+3);
    int index = it - power.begin();

    long long int pick = power[i]*1LL*mp[power[i]] + solve(index, power, mp, dp);

    long long int skip = solve(i+1,power,mp,dp);

    return dp[i] = max(pick,skip);
}
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        unordered_map<int,int>mp;
        for(int i : power){
            mp[i]++;
        }
        vector<int>v;
        for(auto i : mp){
            v.push_back(i.first);
        }

        sort(v.begin(),v.end());
        vector<long long int>dp(n,-1);
        return solve(0,v,mp,dp);
        
    }
};