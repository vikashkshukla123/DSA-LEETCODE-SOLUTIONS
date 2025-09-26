class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = n-1; i>=2; i--){
            long long largest = nums[i];

            long long j = i - 1;
            long long smallerSides = 0;
            long long cnt = 1;
            while(j >= 0){
                smallerSides += nums[j];
                cnt ++;
                j--;
            }

            if(smallerSides > largest && cnt >= 3){
                ans = largest + smallerSides;
                return ans;
            }
            if(smallerSides <= largest){
                continue;
            }
        }
        return -1;

        
    }
};