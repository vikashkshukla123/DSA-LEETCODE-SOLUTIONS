class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        for(int i = 0; i < n; i++){
            pq1.push(nums[i]);
            pq2.push(nums[i]);
        }
        sort(nums.begin(),nums.end());
        if(n == 1) return 0;
        if(n == 2) return (nums[0] + nums[1])/2;
        if(n == 3) return nums[1];

        long long medianSum = 0;
        int idx = 0;
        while(idx < n){
            int ele1 = pq1.top();
            pq1.pop();
            int ele2 = pq1.top();
            pq1.pop();

            int ele3 = pq2.top();
            pq2.pop();

            medianSum += ele2;
            idx += 3;
        }
        return medianSum;
    }
};