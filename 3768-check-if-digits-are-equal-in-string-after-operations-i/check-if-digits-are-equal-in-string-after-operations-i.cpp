class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        while(s.length() != 2){
            string str = "";
            for(int i = 0; i<s.length() - 1; i++){
                int a = s[i] - '0';
                int b = s[i+1] - '0';
                int res = (a+b)%10;
                str += to_string(res);


            }
            s = str;
        }
        return s[0] == s[1];

        
    }
};