class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            bool found = false;
            for(int k = 0; k < nums[i]; k++){
                if((k  | ( k + 1)) == nums[i]){
                    ans.push_back(k);
                    found = true;
                    break;
                }
 
            }
            if(found == false){
                ans.push_back(-1);
            }
        
        }
        return ans;
    }
};