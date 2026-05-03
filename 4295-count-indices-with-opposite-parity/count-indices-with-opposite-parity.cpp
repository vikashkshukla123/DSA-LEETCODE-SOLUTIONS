class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        if(n == 1) return {0};
        for(int i = 0; i<n-1; i++){
            int ele = nums[i];
            int parity = -1;
            if(ele % 2 == 0) parity = 0;
            else parity = 1;
            int cnt = 0;
            for(int j = i+1; j < n; j++){
                if(nums[j] % 2 == 1  && parity == 0) cnt++;
                else if(nums[j] % 2 == 0 && parity == 1) cnt++;

            }
            ans.push_back(cnt);
        }
        ans.push_back(0);
        return ans;
        
    }
};