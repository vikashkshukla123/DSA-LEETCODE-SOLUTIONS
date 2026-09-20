class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>startTime(n,0);
        for(int i = 0; i < n; i++){
            startTime[i] = intervals[i][0];
        }
        long long ans = 0;
        for(int i = 0; i < n-1; i++){
            int value = intervals[i][1];

            int idx = upper_bound(startTime.begin() , startTime.end(),value) - startTime.begin();

                ans += 1LL * ( idx - 1 - i);
                
        }
        return ans;
        
    }
};