class Solution {
public:
    int passwordStrength(string password) {
        int n = password.length();
        unordered_set<char>st;
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            char ch = password[i];
            if(ch >= 'a' && ch <= 'z' && st.find(ch) == st.end()){
                ans++;
                st.insert(ch);
            }else if(ch >= 'A' && ch <= 'Z' && st.find(ch) == st.end()){
                ans += 2;
                st.insert(ch);
            }else if(ch >= '0' && ch <= '9' && st.find(ch) == st.end()){
                ans += 3;
                st.insert(ch);

            }else if(ch == '!' || ch == '@' || ch == '#' || ch == '$'){
                if(st.find(ch) == st.end()){
                    ans += 5;
                    st.insert(ch);
                }
            }
        
        

        }
        return ans;
    }
};