class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        if((abs(start[0] - target[0]) + abs(start[1] - target[1])) % 2 == 0){
            return true;
        }
        return false;
    }
};