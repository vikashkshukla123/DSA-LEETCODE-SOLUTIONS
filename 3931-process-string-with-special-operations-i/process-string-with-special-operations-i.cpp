class Solution {
public:
bool isLower(char ch){
    return (ch >= 'a' && ch <= 'z');
}
    string processStr(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(isLower(s[i])){
                ans += s[i];
            }else if(s[i] == '*'){
                if(ans.size() > 0){
                    ans.pop_back();
                    
                }
            }else if(s[i] == '#'){
                string naya = ans;
                ans += naya;
            }else if(s[i] == '%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};