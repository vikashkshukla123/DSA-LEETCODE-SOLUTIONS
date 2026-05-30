class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int XOR = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
               XOR =  XOR ^ nums[i];
            }
        }
        return XOR;
    }
};