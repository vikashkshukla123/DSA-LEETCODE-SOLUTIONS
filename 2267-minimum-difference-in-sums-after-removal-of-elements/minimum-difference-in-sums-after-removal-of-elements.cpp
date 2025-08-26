class Solution {
    #define ll long long
public:
    long long minimumDifference(vector<int>& nums) {
        ll n = nums.size();
        // Step 1 bulid right sum array from index n/3 to n
        priority_queue<ll,vector<ll>, greater<ll>>minheap;
        ll right_sum = 0;
        vector<ll>right_maxsum(n,0);
        for(ll i=n-1; i>=n/3; i--){
            minheap.push(nums[i]);
            right_sum += nums[i];
            if(minheap.size() > n/3){
                right_sum -= minheap.top();
                minheap.pop();
            }
            if(minheap.size() == n/3){
                right_maxsum[i] = right_sum;
            }
        }
        // STEP 2 compute min_diff moving from 0 to 2n/3
        priority_queue<ll>maxheap;
        ll min_diff = LLONG_MAX;
        ll left_sum = 0;
        for(ll i = 0; i<2*n/3; i++){
            maxheap.push(nums[i]);
            left_sum += nums[i];
            if(maxheap.size() > n/3){
                left_sum -= maxheap.top();
                maxheap.pop();

            }
            if(maxheap.size() == n/3){
                min_diff = min(min_diff, left_sum - right_maxsum[i+1]);
            }

        }
        return min_diff;
        
    }
};