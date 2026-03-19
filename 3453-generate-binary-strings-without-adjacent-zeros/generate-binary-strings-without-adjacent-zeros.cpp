class Solution {
public:
    vector<string> result;
    int N;

    void solve(string s){
        if(s.length() == N){
            result.push_back(s);
            return;
        }

        if(s.back() == '1'){
            solve(s + "0");
            solve(s + "1");
        } else {
            solve(s + "1");
        }
    }

    vector<string> validStrings(int n) {
        N = n;

        solve("0");
        solve("1");

        return result;
    }
};