class Solution {
    vector<string>result;
public:
bool isValid(string validate){
    if(validate[0] == '0'){
        return false;
    }

    int val = stoi(validate);

    if(val <= 255){
        return true;
    }
    return false;
}
void solve(int idx, int parts, string curr, string &s){
    int n = s.length();
    if(idx == n && parts == 4){
        curr.pop_back();
        result.push_back(curr);
        return;

    }

    // taking only ith character
    if(idx + 1 <= n){
        solve(idx + 1, parts + 1, curr + s.substr(idx,1) + ".", s);

       
    }

    if(idx + 2 <= n && isValid(s.substr(idx,2))){
        solve(idx + 2, parts + 1, curr + s.substr(idx,2) + ".",s);
       
    }

    if(idx + 3 <= n && isValid(s.substr(idx,3))){
        solve(idx+3, parts + 1, curr + s.substr(idx,3) + ".",s);
    }

    return;
}
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if(n < 4 || n > 12){
            return {};
        }
        string curr = "";
        solve(0,0,curr,s);

        return result;
        
    }
};