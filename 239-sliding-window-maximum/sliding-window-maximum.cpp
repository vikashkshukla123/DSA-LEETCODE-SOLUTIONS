class Solution {
public:
vector<int>solve(vector<int>&nums, int k){
    int n = nums.size();
    deque<int>dq;
    vector<int>ans;
    int right = 0;

    while(right < n){
        
        while(!dq.empty() && dq.front() <=  right - k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[right] > nums[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(right);


      if(right >= k - 1){
        ans.push_back(nums[dq.front()]);
      }
      right++;




      





    
    }
    
    return ans;
}
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return solve(nums,k);
        
    }
};