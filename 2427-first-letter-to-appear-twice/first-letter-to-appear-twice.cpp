class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.length();
        unordered_set<char>st;
        char ans;
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(!st.empty() && st.find(ch) != st.end()){
                ans = ch;
                break;

            }
            st.insert(ch);
        }
        return ans;
        
    }
};