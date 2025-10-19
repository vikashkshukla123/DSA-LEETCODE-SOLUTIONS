class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = i+1;
        while(j < n){
            if(nums[i] == nums[j]){
                j++;
                continue;
            }
            else{
                i = i+1;
                nums[i] = nums[j];

            }
        }
        return i+1;

        
    }
};