class Solution {
public:
int bestScore = 0;
int solve(int idx, int numArrows, vector<int>&aliceArrows, vector<int>&ans,vector<int>&best){
    int n = aliceArrows.size();
    if(idx >= n || numArrows == 0){
    int score = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] > aliceArrows[i]){
            score += i;
        }
    }
    if(score > bestScore){
        bestScore = score;
        best = ans;

    }

    return score;
    }


    int ans1 = -1e9;
    if(aliceArrows[idx] < numArrows){
        ans[idx] = aliceArrows[idx] + 1;
        ans1 =  idx + solve(idx + 1, numArrows - ans[idx], aliceArrows, ans,best);
        ans[idx] = 0;

    }
    int nottake = solve(idx + 1, numArrows, aliceArrows, ans,best);

    return max(ans1,nottake);

}
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>ans(12,0);
        vector<int>best(12,0);
        solve(0,numArrows, aliceArrows, ans,best);
        int used = 0;
        for(int x : best){
            used += x;
        }

        best[0] += numArrows - used;
        return best;
    }
};