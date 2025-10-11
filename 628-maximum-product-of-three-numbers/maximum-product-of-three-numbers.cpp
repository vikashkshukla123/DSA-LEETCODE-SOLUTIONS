class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = -1e9;
        int i = 0;
        while(i < n-2){
            int j = i+1;
            int k = n-1;
            int sum = 0;
            sum += nums[i]*nums[j]*nums[k];



            if(sum < ans){
                j++;
            }

            ans = max(ans,sum);

            i++;
            
        }
        return ans;
        
    }
};