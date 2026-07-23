class Solution {
public:
bool isPallindrome(string s){
    int i = 0;
    int j = s.length() - 1;
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int idx, string &s, vector<string>ans,vector<vector<string>>&result){
    if(idx == s.length()){
        result.push_back(ans);
    }
    for(int i = idx; i < s.length(); i++){
        if(isPallindrome(s.substr(idx, i - idx + 1))){
            ans.push_back(s.substr(idx, i - idx + 1));
            solve(i + 1, s, ans, result);
            ans.pop_back();
        }
    }

    return;
}
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>>result;
        vector<string>ans;
        solve(0,s,ans,result);

        return result;
    }
};