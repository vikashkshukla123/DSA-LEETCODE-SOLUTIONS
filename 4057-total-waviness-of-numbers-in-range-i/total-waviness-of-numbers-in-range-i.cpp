class Solution {
public:
int count(string &s){
    int n = s.length();
    int ans = 0;
    for(int i = 1; i < n-1; i++){
        if(s[i] > s[i-1] && s[i+1] < s[i]){
            ans++;

        }else if(s[i] < s[i-1] && s[i+1] > s[i]){
            ans++;
        }
    }
    return ans;
}
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            string s = to_string(i);
            if(s.length() < 3){
                continue;
            }
            int waiviness = count(s);
            ans += waiviness;
        }
        return ans;
    }
};