class Solution {
public:
    int dp[301][7][7][7][7];
    vector<int> get(char ch){
        int current_pos = ch - 'A';
        int row = current_pos / 6;
        int col = current_pos % 6;

        return {row, col};
    }

    int getDist(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int idx, int x1, int y1, int x2, int y2){
        int n = word.length();
        if(idx >= n){
            return 0;
        }

        if(dp[idx][x1+1][y1+1][x2+1][y2+1] != -1){
            return dp[idx][x1+1][y1+1][x2+1][y2+1];
        }

        vector<int> coordinates = get(word[idx]);
        int x = coordinates[0];
        int y = coordinates[1];

        int result = 1e9;

        // both fingers unused
        if(x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1){
            return dp[idx][x1+1][y1+1][x2+1][y2+1] = solve(word, idx + 1, x, y, x2, y2);
        }
        // second finger unused
        else if(x2 == -1 && y2 == -1){
            int moveF2 = solve(word, idx + 1, x1, y1, x, y);
            int moveF1 = getDist(x1, y1, x, y) + solve(word, idx + 1, x, y, x2, y2);

            result = min(moveF2, moveF1);
        }
        else{
            int moveF1 = getDist(x1, y1, x, y) + solve(word, idx + 1, x, y, x2, y2);
            int moveF2 = getDist(x2, y2, x, y) + solve(word, idx + 1, x1, y1, x, y);

            result = min(moveF2, moveF1);
        }

        return dp[idx][x1+1][y1+1][x2+1][y2+1] = result;
    }

    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return solve(word, 0, -1, -1, -1, -1);
    }
};