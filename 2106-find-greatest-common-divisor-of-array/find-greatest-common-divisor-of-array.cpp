class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int smallest = 1e9;
        int largest = -1e9;
        for(int i = 0; i < n; i++){
            smallest = min(smallest,nums[i]);
            largest = max(largest, nums[i]);
        }

        return gcd(smallest,largest);
        
    }
};