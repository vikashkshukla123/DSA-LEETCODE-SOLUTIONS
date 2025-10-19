class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for(int i = 0; i<n-1; i++){
            int val1  = s[i] - '0';
            int val2 = s[i+1] - '0';
            if(val1 % 2 == val2 % 2 && val1 > val2){
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};