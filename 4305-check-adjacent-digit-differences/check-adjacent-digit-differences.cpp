class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.length();
        for(int i = 0; i < n-1; i++){
            int val1 = s[i] - '0';
            int val2 = s[i+1] - '0';

            if(abs(val1 - val2) > 2){
                return false;

            }
        }
        return true;
    }
};