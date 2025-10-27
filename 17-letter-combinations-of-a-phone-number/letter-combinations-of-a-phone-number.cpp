class Solution {
    vector<string>ans;
public:
void f(int idx, string digits,unordered_map<char,vector<char>>&mp,string a){
    int n = digits.size();
    if(idx == n){
        ans.push_back(a);
        return;
    }
    vector<char>b = mp[digits[idx]];
    int x = b.size();

    for(int i = 0; i<x; i++){
        a.push_back(b[i]);
        f(idx + 1, digits,mp,a);
        a.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        int n = digits.length();
        unordered_map<char,vector<char>>mp;

        for(int i = 0; i<n; i++){
            char ch = digits[i];
            if(ch == '2'){
                mp[ch] = {'a','b','c'};
            }else if(ch == '3'){
                mp[ch] = {'d','e','f'};
            }else if(ch == '4'){
                mp[ch] = {'g','h','i'};
            }else if(ch == '5'){
                mp[ch] = {'j','k','l'};
            }else if(ch == '6'){
                mp[ch] = {'m','n','o'};
            }else if(ch == '7'){
                mp[ch] = {'p','q','r','s'};
            }else if(ch == '8'){
                mp[ch] = {'t','u','v'};
            }else mp[ch] = {'w','x','y','z'};
        }
        f(0,digits,mp, "");

        return ans;
        
    }
};