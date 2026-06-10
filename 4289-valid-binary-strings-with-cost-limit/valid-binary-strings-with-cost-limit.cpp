class Solution {
public:
vector<string>ans;
void solve(string s, int idx, int n , int k){
    if(idx ==  n){
        ans.push_back(s);
        return;
    }

    if(s[idx-1] == '1'){
        solve(s + "0", idx + 1, n, k);
        s.pop_back();
    }else if(s[idx-1] == '0' && k >= idx){
        solve(s + "1", idx + 1, n , k-idx);
        solve(s + "0" ,idx + 1, n, k);
        s.pop_back();
    }else{
        solve(s + "0" ,idx + 1, n, k);
        s.pop_back();
    }
    
return;

}
    vector<string> generateValidStrings(int n, int k) {
        solve("1",1, n, k);
        solve("0",1, n, k);


        return ans;
        
    }
};