class Solution {
public:
bool isPallindrome(int start, int end , string&s){
    int i = start;
    int j = end;
    while(i <= j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        int maxi = -1e9;
        for(int start = 0; start < n; start ++){
            for(int end = start; end < n; end ++){
                if(isPallindrome(start,end,s)){
                    int len = end - start + 1;
                    if(len > maxi){
                    ans = s.substr(start, end - start + 1);
                    maxi = len;
                }
                }

            }
        }
        return ans;
        
    }
};