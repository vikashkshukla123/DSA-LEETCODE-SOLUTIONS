class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; 2*i<n; i++){
            int freq = nums[2*i];
            int val = nums[2*i + 1];

            while(freq != 0){
                ans.push_back(val);
                freq--;
            }
        }
        return ans;
    }
};