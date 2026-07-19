class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_set<char>st;
        unordered_map<char,int>lastIndex;
        for(int i = n-1; i >= 0; i--){
            if(lastIndex.find(s[i]) == lastIndex.end()){
                lastIndex[s[i]] = i;
            }else{
                continue;
            }
    
        }

        stack<char>stc;
        for(int i = 0; i < n; i++){
            if(st.find(s[i]) != st.end()) continue;
            if(stc.empty() || stc.top() < s[i]  && st.find(s[i]) == st.end()){
                stc.push(s[i]);
                st.insert(s[i]);
                continue;
            }

            while(!stc.empty() && stc.top() > s[i]  && lastIndex.count(stc.top())  && lastIndex[stc.top()] > i){
                
                st.erase(stc.top());
                stc.pop();
            }
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                stc.push(s[i]);
            }
            
        }

        string ans = "";
        while(!stc.empty()){
            ans += stc.top();
            stc.pop();
        }
reverse(ans.begin(),ans.end());
return ans;

        
    }
};