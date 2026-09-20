class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < n-1; i++){
            int end1 = intervals[i][1];
            for(int j = i + 1; j < n; j++){
                int start2 = intervals[j][0];


                if(start2 > end1){
                    continue;
                }
                ans++;
            }
        }
        return ans;
        
    }
};