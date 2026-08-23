class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.length();
        string result;
        for(int i = 0; i < n; i++){
            int val = (int)s[i];
            string str = bitset<8>(val).to_string();
            result += str;
        }
        int i = 0;
        int j = result.length() - 1;
        while(i <= j){
            if(result[i] != result[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};