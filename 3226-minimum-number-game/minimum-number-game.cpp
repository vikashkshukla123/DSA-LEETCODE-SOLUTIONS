class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;

        for(int i = 0; i<n-1; i+=2){
            swap(nums[i],nums[i+1]);
            ans.push_back(nums[i]);
            ans.push_back(nums[i+1]);


        }
        return ans;
    }
};