class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();
        unordered_set<string>st;
        vector<string>ans;
        int idx = 0;
        while(idx < n){
            if(idx == 0){
                string str = "";
                 str += s[0];
                st.insert(str);
                ans.push_back(str);
                idx ++;

            }else{
                string str = "";
                str += s[idx];

                if(st.find(str) == st.end()){
                    st.insert(str);
                    ans.push_back(str);
                    idx++;
                }else{
                    idx++;
                    while(idx < n && st.find(str += s[idx]) != st.end()){
                        idx++;
                    }
                    if(st.find(str) == st.end()){
                    st.insert(str);
                    ans.push_back(str);
                    }
                    idx++;
                }

            }
        }
        return ans;
        
    }
};