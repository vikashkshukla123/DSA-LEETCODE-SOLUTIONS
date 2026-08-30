class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = -1;
        int max_idx = -1;
        int mini = 1e9;
        int maxi = -1e9;

        if(n == 1) return 1;
        for(int i = 0; i < n; i++){
            if(nums[i] < mini){
                min_idx = i;
                mini = nums[i];
            }


            if(nums[i] > maxi){
                max_idx = i;
                maxi = nums[i];
            }
        }
        int case1 = max(min_idx , max_idx) + 1;
        int case2 = n - min(min_idx,max_idx);
        int case3 = min_idx + 1 + n - max_idx;
        int case4 = max_idx + 1 + n - min_idx;

        return min({case1,case2,case3,case4});

    

    }
};