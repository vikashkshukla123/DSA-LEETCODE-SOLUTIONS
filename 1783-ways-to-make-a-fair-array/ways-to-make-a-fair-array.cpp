class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int evenSum = 0;
        int totalSum = 0;
        if(n == 1) return 1;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                evenSum += nums[i];
            }
            totalSum += nums[i];

        }

        vector<int>cumEven(n,0);
        vector<int>cumOdd(n,0);

        cumEven[0] = nums[0];
        cumOdd[1] = nums[1];

        for(int i = 1; i < n; i++){
            if(i % 2 == 1){
                cumEven[i] = cumEven[i-1];
            }else{
                cumEven[i] = cumEven[i-1] + nums[i];
            }
        }


        for(int i = 2; i < n; i++){
            if(i % 2 == 0){
                cumOdd[i] = cumOdd[i-1];
            }else{
                cumOdd[i] = cumOdd[i-1] + nums[i];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int evenSum = 0;
            int oddSum = 0;
            if(i % 2 == 0){
                oddSum = cumEven[n-1] - cumEven[i] +  (i > 0 ? cumOdd[i-1] : 0);
                evenSum = totalSum - nums[i] - oddSum;

            }else{
                evenSum = cumOdd[n-1] - cumOdd[i] + (i > 0 ? cumEven[i-1] : 0);
                oddSum = totalSum - nums[i] - evenSum;

            }

            if(evenSum == oddSum){
                ans++;
            }
        }
return ans;

        
    }
};