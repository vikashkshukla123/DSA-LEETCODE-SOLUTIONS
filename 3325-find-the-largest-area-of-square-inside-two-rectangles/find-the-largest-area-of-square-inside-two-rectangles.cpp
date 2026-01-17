class Solution {
public:

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){

                int x1 = bottomLeft[i][0];
                int y1 = bottomLeft[i][1];


                int x2 = topRight[i][0];
                int y2 = topRight[i][1];


                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];

                int x4 = topRight[j][0];
                int y4 = topRight[j][1];


                int intersected_top_right_x = min(x2,x4);
                int intersected_top_right_y = min(y2,y4);
                int intersected_bottom_left_x = max(x1,x3);
                int intersected_bottom_left_y = max(y1,y3);


                int width = intersected_top_right_x - intersected_bottom_left_x;
                int length = intersected_top_right_y - intersected_bottom_left_y;


                if(width <= 0) continue;
                if(length <= 0) continue;


                long long side = min(width,length);

                long long area = side * side;

                ans = max(ans,area);

                





            }
        }

        return ans;
    }
};