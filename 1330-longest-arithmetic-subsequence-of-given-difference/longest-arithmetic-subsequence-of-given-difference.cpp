class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int,int>mp;
        mp[arr[0]] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            int need = arr[i] - difference;
            if(mp.find(need) != mp.end()){
                ans = max(ans, 1 + mp[need]);
                mp[arr[i]] = 1 + mp[need];
            }else{
                mp[arr[i]] = 1;
            }
        
        }

        return ans;
    }
};