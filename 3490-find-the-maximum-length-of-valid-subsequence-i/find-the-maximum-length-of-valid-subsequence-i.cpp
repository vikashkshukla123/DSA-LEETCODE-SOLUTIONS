class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd_count = 0;
        int even_count = 0;
        int alternate_count = 1;
        bool expecting_even;
        if(nums[0] % 2 == 0){
            expecting_even = false;
            even_count++;
        }
        else{
            expecting_even = true;
            odd_count++;
        }
        for(int i = 1; i<n; i++){
            if((nums[i]%2 == 0 and expecting_even == true) or(nums[i]%2 == 1 and expecting_even == false)){
                alternate_count++;
                expecting_even = !expecting_even;
            }
            
                if(nums[i] % 2 == 0) even_count++;
                else odd_count++;
            }
        return max({even_count, odd_count, alternate_count});
    }
};

