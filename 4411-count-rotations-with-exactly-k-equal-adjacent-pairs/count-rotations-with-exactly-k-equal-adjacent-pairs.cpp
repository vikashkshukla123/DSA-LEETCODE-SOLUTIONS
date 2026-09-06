class Solution {
public:
int calc(string &str){
    int n = str.length();
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        if(str[i] == str[i+1]){
             cnt++;
        }
    }
    return cnt;
}
    int countRotations(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            string str = "";
            str += s.substr(i) + s.substr(0,i);
            int cnt = calc(str);
            if(cnt == k){
                ans++;
            }
        }
        return ans;
        
    }
};