class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Rook attack (same row)
        if (a == e) {
            // check if bishop blocks horizontally
            if (!(c == a && ((b < d && d < f) || (f < d && d < b))))
                return 1;
        }

        // Rook attack (same column)
        if (b == f) {
            // check if bishop blocks vertically
            if (!(d == b && ((a < c && c < e) || (e < c && c < a))))
                return 1;
        }

        // Bishop attack (same diagonal)
        if (c - d == e - f) {
            // same main diagonal
            if (!((a - b == e - f) && ((c < a && a < e) || (e < a && a < c))))
                return 1;
        }

        if (c + d == e + f) {
            // same anti-diagonal
            if (!((a + b == e + f) && ((c < a && a < e) || (e < a && a < c))))
                return 1;
        }

        // Otherwise, needs 2 moves
        return 2;
    }
};
