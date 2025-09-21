class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int m = shifts.size();
        vector<int>a(n,0);
        for(int i = 0; i<m; i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 0){
                a[start] += -1;
                if(end + 1 < n){
                a[end + 1] -= -1;
                }
            }else{
                a[start] += 1;
                if(end + 1 < n){
                    a[end + 1] -=1;
                }
            }
        }

        a[0] = a[0] % 26;

        if(a[0] < 0){
            a[0] = a[0] + 26;
        }
        // finding the cumulative sum;
        for(int i = 1; i<n; i++){
            a[i] = a[i] + a[i-1];
            a[i] = a[i] % 26;
            if(a[i] < 0){
                a[i] = a[i] + 26;
            }
            
        }

        string ans = "";
        for(int i = 0; i<n ;i++){
            char ch = ((s[i] - 'a' + a[i]) % 26) + 'a';
            ans += ch;
        }
return ans;

        
        
    }
};