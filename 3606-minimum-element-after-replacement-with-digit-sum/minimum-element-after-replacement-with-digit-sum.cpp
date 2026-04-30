class Solution {
public:
int calc(int num){
    int sum = 0;
    while(num != 0){
        int val = num % 10;
        sum += val;
        num = num / 10;

    }
    return sum;
}
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9;
        for(int i = 0; i<n; i++){
            int val = calc(nums[i]);
            mini = min(mini,val);
        }
        return mini;
    }
};