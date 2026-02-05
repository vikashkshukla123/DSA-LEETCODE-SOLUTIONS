class Solution {
public:

    // FIXED: function name (removed space)
    bool isValid(int x_dash, int y_dash,
                 int x1, int y1,
                 int x2, int y2,
                 int x3, int y3,
                 int x4, int y4) {

        // left line
        if (x_dash == x1 && y_dash > y1 && y_dash < y3) return false;

        // bottom line
        if (y_dash == y1 && x_dash > x1 && x_dash < x4) return false;

        // right line
        if (x_dash == x4 && y_dash > y4 && y_dash < y2) return false;

        // top line
        if (y_dash == y3 && x_dash > x3 && x_dash < x2) return false;

        // inside
        if (x_dash > x1 && x_dash < x2 && y_dash > y1 && y_dash < y2)
            return false;

        return true;
    }

    int maxRectangleArea(vector<vector<int>>& points) {

        // FIXED: nums → points
        int n = points.size();
        int ans = -1;

        sort(points.begin(), points.end());

        // FIXED: unordered_set<pair> needs hash → encoded long long
        unordered_set<long long> st;
        auto encode = [&](int x, int y) {
            return ((long long)x << 32) | (unsigned int)y;
        };

        for (int i = 0; i < n; i++) {
            st.insert(encode(points[i][0], points[i][1]));
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                int bottom_left_x1 = points[i][0];
                int bottom_left_y1 = points[i][1];

                int top_right_x2 = points[j][0];
                int top_right_y2 = points[j][1];

            
                if (bottom_left_x1 >= top_right_x2 ||
                    bottom_left_y1 >= top_right_y2)
                    continue;

                int top_left_x1 = bottom_left_x1;
                int top_left_y1 = top_right_y2;

                int bottom_right_x2 = top_right_x2;

                int bottom_right_y2 = bottom_left_y1;

                bool a_found = false;
                bool b_found = false;

                // FIXED: set iteration
                for (auto it : st) {
                    int x_dash = it >> 32;
                    int y_dash = (int)it;

                    if ((x_dash == bottom_left_x1 && y_dash == bottom_left_y1) ||
                        (x_dash == top_right_x2 && y_dash == top_right_y2))
                        continue;

    
                    if (x_dash == top_left_x1 && y_dash == top_left_y1) {
                        a_found = true;
                        continue;
                    }

                    if (x_dash == bottom_right_x2 && y_dash == bottom_right_y2) {
                        b_found = true;
                        continue;
                    }
                }

                if (a_found && b_found) {
                    bool valid = true;

                    for (auto it : st) {
                        int x_dash = it >> 32;
                        int y_dash = (int)it;

                        if (!isValid(x_dash, y_dash,
                                     bottom_left_x1, bottom_left_y1,
                                     top_right_x2, top_right_y2,
                                     top_left_x1, top_left_y1,
                                     bottom_right_x2, bottom_right_y2)) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        int length = bottom_right_x2 - bottom_left_x1;
                        int breadth = top_left_y1 - bottom_left_y1;
                        ans = max(ans, length * breadth);
                    }
                }
            }
        }
        return ans;
    }
};
