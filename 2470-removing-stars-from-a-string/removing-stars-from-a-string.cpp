class Solution {
public:
bool isStar(char ch){
    return (ch == '*');
}
    string removeStars(string s) {
        int n = s.length();
        stack<char>st;
        int i = 0;
        while(i < n){
            if(!st.empty() && isStar(s[i])){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};