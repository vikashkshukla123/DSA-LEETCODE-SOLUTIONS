class Solution {
public:
    int M;
    int N;
    int mod = 1e9 + 7;
    vector<string>possibilities;
int solve(int idx, int col_left,vector<vector<int>>&dp){
    if(col_left == 0){
        return 1;
    }

    int ways = 0;

    if(dp[idx][col_left] != -1){
        return dp[idx][col_left];
    }




    string prev_state = possibilities[idx];

    for(int i = 0; i<possibilities.size(); i++){
        if(i == idx) continue;

        string current = possibilities[i];
        bool valid = true;
        for(int j = 0; j<M; j++){
            if(prev_state[j] == current[j]){
                valid = false;
                break;
            }
        }
        if(valid){
            ways = (ways + solve(i, col_left - 1,dp)) % mod;
        }
    }
    return dp[idx][col_left] = ways;
}
void generate(string s, int length, char prev){
    if(length == M){
        possibilities.push_back(s);
        return;
    }

    for(char ch : {'R','G','B'}){
        if(ch == prev){
            continue;
            
        }
        generate(s+ch, length + 1, ch);
    }
}
    int colorTheGrid(int m, int n) {
        M = m;
        N = n;

        generate("", 0, '#');
        int result = 0;
        int i_value = possibilities.size();
        vector<vector<int>>dp(i_value, vector<int>(n, -1));

        for(int i = 0; i<possibilities.size(); i++){
            result = (result + solve(i,n-1,dp)) % mod;

        }


        return result;
        
        
    }
};