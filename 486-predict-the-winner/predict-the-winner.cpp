class Solution {
public:
int solve(int left, int right, vector<int>&nums){
    int n = nums.size();
    if(left > right){
        return 0;
    }

    if(left < 0 || right >= n){
        return 0;
    }
    int case1 = 0;
    int case2 = 0;
    int ans1 = 1e9;
    int ans2 = 1e9;
    case1 = nums[left] - min(ans1,solve(left + 1, right, nums));
    case2 = nums[right] - min(ans2, solve(left, right - 1, nums));


    return max(case1,case2);


    return case1;

    
}
    bool predictTheWinner(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
       

        int ans = solve(0,n-1,nums);
        return (ans >= 0);
        
    }
};