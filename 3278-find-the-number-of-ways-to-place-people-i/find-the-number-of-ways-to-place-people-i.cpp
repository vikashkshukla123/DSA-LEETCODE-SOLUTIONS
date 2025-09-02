class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[](const vector<int>&p1, const vector<int>&p2){
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });

        int cnt = 0;
        for(int A = 0; A < n-1; A++){
            int bottom_right_y = -1e9;
            for(int B = A+1; B<n; B++){
                if(points[B][1] <= points[A][1] and points[B][1] > bottom_right_y){
                    cnt++;
                    bottom_right_y = points[B][1];
                }
            }
        }
        return cnt;
    }
};