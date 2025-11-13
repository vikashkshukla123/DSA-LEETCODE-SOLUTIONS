class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int cnt1 = 0;
        int operations = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                operations += cnt1;
                while(i < n && s[i] == '0'){
                    i++;
                }
            }else{
                cnt1++;
                i++;
            }
        }
        return operations;
    }
};