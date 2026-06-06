class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        for(int i = 0; i < n; i++){
            if(i == 0){
                ans.push_back(totalSum - nums[0]);
            }else if(i == n-1){
                ans.push_back(totalSum - nums[n-1]);
            }else{
                int j = i-1;
                int k = i + 1;
                int leftSum = 0;
                int rightSum = 0;
                while(j >= 0){
                    leftSum += nums[j];
                    j--;
                }

                while(k < n){
                    rightSum += nums[k];
                    k++;
                }

                ans.push_back(abs(leftSum - rightSum));
            }


        

           
        }

        return ans;
        
    }
};