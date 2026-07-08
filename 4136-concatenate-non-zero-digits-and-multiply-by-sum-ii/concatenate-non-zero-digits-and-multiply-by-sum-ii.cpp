class Solution {
public:
int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long>sumTill(n,0);
        sumTill[0] = s[0] - '0';
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                sumTill[i] = sumTill[i-1];
            }else{
                sumTill[i] = sumTill[i-1] + (s[i] - '0');
            }
        }

        vector<long long>numberTill(n,0);
        numberTill[0] = s[0] - '0';
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                numberTill[i] = (numberTill[i-1]) % mod;
            }else{
                numberTill[i] = ((numberTill[i-1] * 10) + s[i] - '0') % mod;
            }
        }

        vector<int>nonZeroTill(n,0);
        if(s[0] != '0'){
            nonZeroTill[0] = 1;
        }else{
            nonZeroTill[0] = 0;
        }

        for(int i = 1; i < n; i++){
            if(s[i]  != '0'){
                nonZeroTill[i] = 1 + nonZeroTill[i-1];
            }else{
                nonZeroTill[i] = nonZeroTill[i-1];
            }

        }

        vector<long long>pow10(n+1,0);
        pow10[0] = 1;
        for(int i = 1; i < n; i++){
            pow10[i] = (pow10[i-1] * 10) % mod;
        }


        int m = queries.size();
        vector<int>result(m,0);
        for(int i = 0; i < m; i++){
            int left = queries[i][0];
            int right = queries[i][1];

            long long sum = sumTill[right] - (left - 1 >= 0 ? sumTill[left-1] : 0); 

            int numBefore = (left == 0) ? 0 : numberTill[left-1];
            int k = nonZeroTill[right] - (left - 1 >= 0 ? nonZeroTill[left-1] : 0);
            long long x =  (numberTill[right] - (numBefore * pow10[k] % mod) + mod) % mod;  
        
            long long  ans = (1LL * sum * x) % mod;

            result[i] = (int) ans;
            




        }

        return result;
        
    }
};