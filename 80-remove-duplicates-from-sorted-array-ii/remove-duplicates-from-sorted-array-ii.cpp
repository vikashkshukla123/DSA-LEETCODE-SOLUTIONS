class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }

        vector<int>res;
        res.push_back(nums[0]);
        res.push_back(nums[1]);
        int i = 2;
        for(int i = 2; i<n; i++){
            int num1 = nums[i];
            int num2 = nums[i-2];

            if(num1 == num2){
                continue;
            }else{
                res.push_back(num1);
            }
        }

        nums = res;
        return res.size();
        
    }
};