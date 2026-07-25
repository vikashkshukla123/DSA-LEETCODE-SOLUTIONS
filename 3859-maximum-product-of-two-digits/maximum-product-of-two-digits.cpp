class Solution {
public:
    int maxProduct(int n) {
         string s = to_string(n);
         sort(s.begin(),s.end());

         int m = s.length();
         int val1 = s[m-1] - '0';
         int val2 = s[m-2] - '0';


         return (val1 * val2);
        
    }
};