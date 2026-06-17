class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        int n = s.length();
        for(char &ch : s){
            if(ch == '*'){
                if(length > 0){
                    length = length - 1;
                }
            }else if(ch == '#'){
                length *= 2;
            }else if(ch == '%'){
                continue;
            }else{
                length++;
            }
        }

        
        if(k >= length) return '.';
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '*'){
                length = length + 1;
            }else if(s[i] == '#'){
                length = length / 2;
                k = (k >= length) ? k - length : k;
            }else if(s[i] == '%'){
                 k = length - k - 1;
            }else{
                length = length - 1;
            }


            if(k == length){
                return s[i];
            }
        }

        return '.';
        
    }
};