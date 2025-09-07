class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        unordered_set<char>st;
        for(int i = 0; i<n; i++){
            st.insert(s[i]);
        }
        string str = "";
        while(!st.empty()){
            auto it = st.begin();
            str += *it;
            st.erase(it);
        }
        sort(str.begin(),str.end());
        stack<char>st1;
        for(int i = str.length() - 1; i >= 0; i--){
            st1.push(str[i]);
        }

        int ans = 0;
        while(!st1.empty()){
            char ch = st1.top();
            st1.pop();
            if(ch == 'a') continue;
            if(st1.empty()){
                ans += 'z' - ch + 1;
            }else{
                ans += st1.top() - ch;

            }
        }
        return ans;



        
    }
};