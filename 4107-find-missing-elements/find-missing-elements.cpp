class Solution {
public:
bool findkr(int ele, vector<int>&nums){
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == ele){
            return true;
        }
    }
    return false;
}
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int min_ele = nums[0];
        int max_ele = nums[n-1];
        vector<int>ans;

        for(int i = min_ele + 1; i<max_ele; i++){
            bool find = findkr(i,nums);
            if(!find){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {};
        return ans;

        
        
    }
};