class Solution {
public:
int solve(int left, int right, vector<int>&nums){
    int n = nums.size();
    if(left > right){
        return 0;
    }
    if(left >= n || right < 0){
        return 0;
    }

    int case1 = nums[left] + min(solve(left + 2,right,nums), solve(left + 1, right -1,nums));
    int case2 = nums[right] + min(solve(left+1,right - 1,nums), solve(left, right - 2,nums));

    return max(case1,case2);
}
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalScore = 0;
        for(int i = 0; i < n; i++){
            totalScore += nums[i];
        }
        int ans1 = solve(0,n-1,nums);
        int ans2 = totalScore - ans1;

        return (ans1 >= ans2);
    }
};