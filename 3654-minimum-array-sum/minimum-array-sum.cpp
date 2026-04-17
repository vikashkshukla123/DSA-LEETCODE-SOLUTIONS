class Solution {
public:
int n;
int t[101][101][101];
int solve(int idx, int op1, int op2, vector<int>&nums, int k){
    if(idx == n){
        return 0;

    }
    if(t[idx][op1][op2] != -1){
        return t[idx][op1][op2];
    }

    int result = INT_MAX;

    // case1 apply operation 1 on particular index
    if(op1 > 0){
        int newVal = (nums[idx] + 1)/2;
        int applyOp1 = newVal + solve(idx + 1, op1 - 1, op2, nums,k);
        result = min(result, applyOp1);

    }

    if(op2 > 0 && nums[idx] >= k){
        int newVal = nums[idx] - k;
        int applyOp2 = newVal + solve(idx + 1, op1 , op2 - 1, nums,k);
        result = min(result, applyOp2);

    }

    if(op1 > 0 && op2 > 0){
        int newValue = (nums[idx] + 1)/2;

        if(newValue >= k){
            newValue = newValue - k;
            int applyOp3 = newValue + solve(idx + 1, op1 - 1, op2 - 1, nums,k);
            result = min(result, applyOp3);


        }


        if(nums[idx] >= k){
            newValue = nums[idx] - k;

            newValue = (newValue + 1)/2;

            int applyOp4 = newValue + solve(idx + 1, op1 - 1, op2 - 1, nums,k);
            result = min(result, applyOp4);
            
        }
    }


result = min(result, nums[idx] + solve(idx + 1, op1, op2, nums,k));

return t[idx][op1][op2] = result;


}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0,op1,op2,nums,k);
        
    }
};