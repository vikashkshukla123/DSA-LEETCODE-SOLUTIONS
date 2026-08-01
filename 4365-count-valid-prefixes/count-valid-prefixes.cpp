class Solution {
public:
bool isAlternating(string &str){
    int cnt1 = 0;
    int cnt0 = 0;
    int n = str.length();
    if(n == 1){
        return true;
    }
    for(int i = 0; i < n; i++){
        if(str[i] - '0' == 1){
            cnt1++;
        }else{
            cnt0++;
        }
    }
  int diff = abs(cnt1 - cnt0);

  return (diff <= 1);
}
    int countValidPrefixes(string s) {
        int n = s.length();
        int ans = 0;
        string str = "";
        int idx = 0;
        while(idx < n){
            str += s[idx];
            if(isAlternating(str)){
                ans++;
            }
            idx++;
        }
        return ans;
    }
};