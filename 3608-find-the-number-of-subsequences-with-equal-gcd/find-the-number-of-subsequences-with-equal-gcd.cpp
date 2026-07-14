class Solution {
public:
int mod = 1e9 + 7;
int t[201][201][201];
int solve(int idx, int gcd1, int gcd2, vector<int>&nums){
    int n = nums.size();
    if(idx == n){
        bool bothNonEmpty = (gcd1 != 0 && gcd2 != 0);
        bool gcdMatch = (gcd1 == gcd2);

        return (bothNonEmpty && gcdMatch) ? 1: 0;
    } 
    if(t[idx][gcd1][gcd2] != -1){
        return t[idx][gcd1][gcd2];
    }

    int skip = solve(idx + 1, gcd1, gcd2, nums);
    int takeFirst = solve(idx + 1, __gcd(gcd1, nums[idx]),gcd2, nums);
    int takeSecond = solve(idx + 1, gcd1, __gcd(gcd2, nums[idx]),nums);
    return t[idx][gcd1][gcd2] = (0LL +  skip + takeFirst + takeSecond) % mod;
}
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(0,0,0,nums);
        
    }
};