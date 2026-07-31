class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        int left = 0;
        int right = 0;
        int size = 2 * k + 1;
        long long sum = 0;
        while(right < n){
            sum += nums[right];

            while(left < n && right - left + 1 > size){
                sum -= nums[left];
                left++;
            }

            if(right - left + 1 ==  size){
                ans[right  - k] = sum/size;
            }
            right++;
        }

        return ans;
        
    }
};