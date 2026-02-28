class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        int ans = 0;


        while(left < right){
            int sum1 = nums[left];
            int sum2 = k - sum1;

            if(nums[left] == sum1 && nums[right] == sum2){
                ans++;
                left++;
                right--;
            }else if(sum2 > nums[right]){
                left++;

            }else if(nums[right] > sum2){
                right--;
            }
        }
        return ans;
    }
};