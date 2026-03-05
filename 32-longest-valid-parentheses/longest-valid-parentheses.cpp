class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int>ones(n,0);
        stack<int>st;
        for(int i = 0; i<n; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }


            if(!st.empty() && s[st.top()] == '(' && s[i] == ')'){
                ones[i] = 1;
                ones[st.top()] = 1;
                st.pop();

            }else{
                st.push(i);
            }
            


        }
        

        int result = 0;
        int i = 0;
        while(i < n){
            int ans = 0;
            if(ones[i] == 0){
            ans = 0;
            i++;
            continue;
            }

            while(ones[i] != 0){
                ans += ones[i];
                i++;
                if(i >= n){
                    break;
                }
            }

            result = max(result, ans);

            
        }

        return result;
    }
};