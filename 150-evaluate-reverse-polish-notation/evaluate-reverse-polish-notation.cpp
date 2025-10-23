class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<string>st;
        for(int i = 0; i<tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-"  && tokens[i] != "*" &&tokens[i] != "/"){
                st.push(tokens[i]);
            }else{
                int b = stoi(st.top());
                st.pop();
                int a = stoi(st.top());
                st.pop();

                string op = tokens[i];
                if(op == "+"){
                    ans = a+b;
                    st.push(to_string(ans));
                }else if(op == "-"){
                    ans = a-b;
                    st.push(to_string(ans));
                }else if(op == "*"){
                    ans = a*b;
                    st.push(to_string(ans));
                }else{
                    ans = float(a/b);
                    st.push(to_string(ans));
                }


                
            }
        }
       string res = st.top();
       return stoi(res);

        
    }
};