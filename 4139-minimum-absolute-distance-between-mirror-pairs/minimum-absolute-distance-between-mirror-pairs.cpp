class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            if(mp.empty()){
                string s = to_string(nums[i]);
                reverse(s.begin(),s.end());
                int num = stoi(s);
                mp[num] = i;
                continue;
            }
            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans, abs(mp[nums[i]] - i));
            }
            string s = to_string(nums[i]);
                reverse(s.begin(),s.end());
                int num = stoi(s);
                mp[num] = i;




        }
        return ans == 1e9 ? -1 : ans;
        
    }
};