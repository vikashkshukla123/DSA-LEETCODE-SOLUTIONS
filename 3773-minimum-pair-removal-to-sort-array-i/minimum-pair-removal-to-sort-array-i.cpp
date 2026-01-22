class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }

      int cnt = 0;
      while(!is_sorted(nums.begin(),nums.end())){
        int min_val = 1e9;
        int min_idx = -1;
        cnt++;
      for(int i = 0; i<nums.size() - 1; i++){
        int val = nums[i] + nums[i+1];
        if(val < min_val){
            min_val = val;
            min_idx = i;
        }
      }

      nums[min_idx] = min_val;
      nums.erase(nums.begin() + min_idx + 1);
      }

      return cnt;
    }
};