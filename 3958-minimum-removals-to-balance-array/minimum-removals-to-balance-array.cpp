class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;

        while(i < n){
            int min_element = nums[i];

            while((j < n) && (nums[j] <= (long long)k * nums[i])){
                j++;
            }

            ans = min(ans, n   - (j - i));

            i++;




        }
        return ans;
    }
};