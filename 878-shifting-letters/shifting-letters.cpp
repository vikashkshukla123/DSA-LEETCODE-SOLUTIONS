class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        vector<long long>a(n,0);
        for(int i = 0; i<n; i++){
            int start = 0;
            int end = i;


            a[start] += shifts[i];
            if(end + 1 < n){
                a[end + 1] -= shifts[i];
            }
        }
        for(int i = 1; i<n; i++){
            a[i] = a[i] + a[i-1];
            a[i] = a[i] % 26;
            if(a[i] < 0){
                a[i] = a[i] + 26;
            }
        }

        string t = "";
        for(int i = 0; i<n; i++){
            char ch = ((s[i] - 'a' + a[i]) % 26) + 'a';
            t += ch;

        }

return t;
        
    }
};