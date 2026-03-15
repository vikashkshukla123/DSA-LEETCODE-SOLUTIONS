class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0){
                mp[nums[i]]++;
            }
        }

        int ans = -1;
        for(int i = 0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                if(mp[nums[i]] == 1){
                    ans = nums[i];
                    break;
                }
            }
        }
        return ans;
        
    }
};