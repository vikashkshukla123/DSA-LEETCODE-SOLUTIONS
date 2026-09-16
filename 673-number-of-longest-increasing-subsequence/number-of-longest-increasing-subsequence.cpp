class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis(n,1);
        vector<int>count(n,1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                   if(lis[j] + 1 == lis[i]){
                    count[i] += count[j];
                   }else if(lis[j] + 1 > lis[i]){
                    lis[i] = 1 + lis[j];
                    count[i] = count[j];
                   }
                }
            }
        }
        
int ans = 0;
int maxi = *max_element(lis.begin(),lis.end());
for(int i = 0; i < n; i++){
    if(lis[i] == maxi){
       ans += count[i];
    }
}

return ans;
    
        
    }
};