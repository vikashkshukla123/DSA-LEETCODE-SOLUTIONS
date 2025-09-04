class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int x_take = abs(z-x);
        int y_take = abs(z-y);

        if(x_take < y_take) return 1;
        else if(x_take > y_take) return 2;
        else return 0;
    }
};