class Solution {
public:
    void solve(int idx, int cnt, string & current, string& s, int& maxlen,
               set<string>& st) {
        int n = s.length();
        if (cnt < 0) {
            return;
        }

        if (idx == n) {
            if (cnt == 0) {
                if (current.length() < maxlen)
                    return;
                int sz = current.length();
                maxlen = max(maxlen, sz);
                st.insert(current);
            }

            return;
        }

        if (s[idx] != '(' && s[idx] != ')') {
            current.push_back(s[idx]);
            solve(idx + 1, cnt, current, s, maxlen, st);
            current.pop_back();
        } else {
            solve(idx + 1, cnt, current, s, maxlen, st);
            current.push_back(s[idx]);
            solve(idx + 1, s[idx] == '(' ? cnt + 1 : cnt - 1, current,
                  s, maxlen, st);
            current.pop_back();
        }
    

    

        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        set<string> st;
        int maxlen = 0;
        string current = "";
        solve(0, 0, current, s, maxlen, st);
        vector<string> ans;
        for (auto it = st.begin(); it != st.end(); it++) {
            string val = *it;
            if (val.length() == maxlen) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};