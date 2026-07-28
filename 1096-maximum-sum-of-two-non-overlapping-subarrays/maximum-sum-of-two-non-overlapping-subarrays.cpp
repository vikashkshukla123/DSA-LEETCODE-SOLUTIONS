class Solution {
public:
int solve(int idx, vector<int>&nums, int len){
    int n = nums.size();
    int left = idx;
    int right = idx;
    int currSum = 0;
    int maxSum = 0;
    while(right < n){
        currSum += nums[right];
        while(left < n && right - left + 1 > len){
            currSum -= nums[left];
            left++;
        }
        if(right - left + 1 == len){
            maxSum = max(maxSum,currSum);
        }
        right++;
    }

    return maxSum;
}
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
         int n = nums.size();
         vector<int>prefixMax1(n,0);
         int left = 0;
         int right = 0;
         int sum = 0;
         while(right < n){
            sum += nums[right];
            while(left < n && right - left + 1 > firstLen){
                sum -= nums[left];
                left++;
            }
            if(right - left + 1 == firstLen){
                prefixMax1[right] = right - 1 >= 0 ? max(prefixMax1[right-1], sum) : sum;
            }
            right++;
         }
         int ans1 = 0;
         for(int i = firstLen-1; i < n - secondLen; i++){
              int maxLeftSum = prefixMax1[i];
              int maxRightSum = solve(i+1,nums, secondLen);
              ans1 = max(ans1, maxLeftSum + maxRightSum);

         }
         vector<int>prefixMax2(n,0);
         left = 0;
         right = 0;
         sum = 0;
         while(right < n){
            sum += nums[right];
            while(left < n && right - left + 1 > secondLen){
                sum -= nums[left];
                left++;
            }
            if(right - left + 1 == secondLen){
                prefixMax2[right] = right - 1 >= 0 ? max(prefixMax2[right-1], sum) : sum;
            }
            right++;
         }


         int ans2 = 0;
         for(int i = secondLen-1; i < n - firstLen; i++){
            int maxLeftSum = prefixMax2[i];
            int maxRightSum = solve(i+1, nums,firstLen);
            ans2 = max(ans2, maxLeftSum +  maxRightSum);

         }


return max(ans1,ans2);








         
    }
};