class Solution {
public:
    bool isPossible(vector<vector<int>>& squares, double mid, double totalArea) {
        double bottomArea = 0.0;

        for (auto &square : squares) {
            double bottom_y = square[1];
            double side = square[2];
            double top_y = bottom_y + side;

            if (mid >= top_y) {
                bottomArea += side * side;
            }
            else if (mid > bottom_y) {
                bottomArea += side * (mid - bottom_y);
            }
        }

        return bottomArea >= totalArea / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double left = 1e18, right = -1e18;

        for (auto &sq : squares) {
            double side = sq[2];
            totalArea += side * side;
            left = min(left, (double)sq[1]);
            right = max(right, (double)sq[1] + side);
        }

        double ans = 0.0;

        while (right - left > 1e-5) {
            double mid = left + (right - left) / 2.0;

            if (isPossible(squares, mid, totalArea)) {
                ans = mid;
                right = mid;
            } else {
                left = mid;
            }
        }

        return ans;
    }
};
