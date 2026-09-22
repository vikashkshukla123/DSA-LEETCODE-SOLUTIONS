class Solution {
public:
unordered_map<int,unordered_map<char,long long>>mp;
void solve(int value){
    string s = to_string(value);
    int n = s.length();
    for(int i = 0; i < n; i++){
        mp[i][s[i]]++;
    }
}
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            solve(nums[i]);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++){
            int value = nums[i];
            string s = to_string(value);
            for(int j = 0; j < s.length(); j++){
                long long freq = mp[j][s[j]];
                ans += (1LL* n - freq);
            }
        }




return (ans / 2);
        
        
    }
};