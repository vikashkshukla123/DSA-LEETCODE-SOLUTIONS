class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i < n){
            int j = i;
            int count = 0;
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            if(j < n){
                count = n - j;
            }
            if(count >= k){
                cnt += j - i;
            }

            i = j;
        }
        return cnt;
        
    }
};