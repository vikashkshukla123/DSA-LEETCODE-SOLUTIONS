class Solution {
public:
    int minSensors(int n, int m, int k) {
        double num_rows = n;
        double num_cols = m;
        int block = 2 * k + 1;
        int totalRow = ceil(num_rows/block);
        int totalCol = ceil(num_cols/block);


        return totalRow*totalCol;
    }
};