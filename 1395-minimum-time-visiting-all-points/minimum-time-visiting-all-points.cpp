class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            int point_x1 = points[i][0];
            int point_y1 = points[i][1];

            int point_x2 = points[i+1][0];
            int point_y2 = points[i+1][1];


            int d1 = abs(point_x1 - point_x2);
            int d2 = abs(point_y1 - point_y2);


            ans += max(d1,d2);
        }
        return ans;
    }
};