class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string other = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '0'){
                continue;
            }else{
                other += s[i];
            }

        }

        long long ans = stoll(other);
        return ans;
        
    }
};