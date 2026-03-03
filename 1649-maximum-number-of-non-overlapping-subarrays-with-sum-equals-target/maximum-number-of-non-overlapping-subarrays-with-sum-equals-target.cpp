class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>prefixSum(n+1,0);

        prefixSum[0] = 0;
        for(int i = 0; i<n; i++){
            prefixSum[i+1] = nums[i] + prefixSum[i];
        }

        int ans = 0;
        int last_idx = -1;
        unordered_map<int,int>mp;
        for(int i = 0; i<=n; i++){
            int sum = prefixSum[i];
            int extra = sum - target;

            if(mp.find(extra) == mp.end()){
                mp[sum] = i;
            }else{
                int idx = mp[extra];

                if(ans == 0){
                    ans++;
                    mp[sum] = i;
                    last_idx = i;
                }else{
                    int idx1 = idx + 1;
                    int idx2 = i;

                    if(last_idx >= idx1 && last_idx <= i){
                        mp[sum] = i;
                        continue;
                    }else{
                        ans++;
                        mp[sum] = i;
                        last_idx = i;
                    }


                   
                }
            }
        }
        return ans;
    }
};