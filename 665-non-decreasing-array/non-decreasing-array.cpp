class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int modification = 0;
        for(int i = 1; i<n; i++){
            if(nums[i-1] > nums[i]){
                modification++;


                if(i >= 2 && nums[i-2]  > nums[i]){

                    nums[i] = nums[i-1];

                }else{
                    nums[i-1] = nums[i];
                }
            }
        }
        return modification <= 1;
    }
};