class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        int bitwise_or = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                bitwise_or = bitwise_or | nums[i];
            }
        }

        return bitwise_or;
    }
};