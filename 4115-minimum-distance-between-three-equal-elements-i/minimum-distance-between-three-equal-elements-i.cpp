class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e9;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(i != j && j != k && k != i && nums[i] == nums[j] && nums[j] == nums[k]){
                        ans = min(ans, abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
       return ans == 1e9 ? -1 : ans;
        
    }
};