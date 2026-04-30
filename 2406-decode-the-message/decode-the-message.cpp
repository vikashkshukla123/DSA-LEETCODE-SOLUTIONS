class Solution {
public:
    string decodeMessage(string key, string message) {
        int n = key.length();
        vector<char>vec;
        unordered_set<char>st;
        for(int i = 0; i<n; i++){
            if(key[i] == ' ') continue;
            if(st.find(key[i]) == st.end()){
                st.insert(key[i]);
                vec.push_back(key[i]);
            }
        }
        unordered_map<char,char>mp;
        char ch = 'a';
        for(int i = 0; i<vec.size(); i++){
            mp[vec[i]] = ch;
            ch++;
        }

        string ans = "";
        for(int i = 0; i < message.length(); i++){
            if(message[i] == ' '){
                ans += " ";
            }else{
                ans += mp[message[i]];
            }
        }

return ans;

    }
};