class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        unordered_map<long,int>mp[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                long diff = (long)nums[i] - nums[j];
                auto it = mp[j].find(diff);

                int cnt_at_j = it == end(mp[j]) ? 0 : it->second;

                mp[i][diff] ++;
                mp[i][diff] += cnt_at_j;
                ans += cnt_at_j;
            }
            
        }
        
        return ans;
    }
};