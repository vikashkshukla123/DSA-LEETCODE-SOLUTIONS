class Solution {
    int solve(int n, int currA, int clipA){
        if(currA == n){
            return 0;
        }
        if(currA > n) return (int)1e9;

        int case1 = 2 + solve(n, currA + currA,  currA);

        int case2 = 1 + solve(n, currA + clipA, clipA);

        return Math.min(case1,case2);
    }
    public int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        return 1 + solve(n, 1,1);
        
    }
}