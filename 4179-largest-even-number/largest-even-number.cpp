class Solution {
public:
    string largestEven(string s) {
        int n = s.length();
        int last = s[n-1] - '0';
        if(last % 2 == 0){
            return s;
        }
        string ans = "";
        for(int i = n-1; i>=0; i--){
            if((s[i] - '0') % 2 != 0){
                continue;
            }
            else{
                return  s.substr(0, i+1);
            }
        }
        return ans;
    }
};