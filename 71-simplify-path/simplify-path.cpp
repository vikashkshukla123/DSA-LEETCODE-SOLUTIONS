class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string>st;
        string token = "";
        while(getline(ss, token, '/')){
           if(token == "." || token == "") continue;
           if(token != ".."){
            st.push(token);
           }else if(!st.empty()){
            st.pop();
           }

        }
        string res = "";
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        

        return res;
    }
};