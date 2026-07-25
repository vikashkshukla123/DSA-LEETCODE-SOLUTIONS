class Solution {
public:
int N;
vector<vector<int>>ans;
void solve(int i, int j, int value, int n){
    if(i < 0 || j < 0 || i >= N || j >= N){
        return;
    }

    if(n == 1){
        ans[i][j] = value;
        return;
    }
    int len = n/2;
    int cells = len * len;

    solve(i , j, value,len);
    solve(i , j + n/2, value - cells * 3,len);
    solve(i+n/2,j+n/2, value - cells * 2, len);
    solve(i + n/2, j, value - cells * 1, len);


    return;
}
    vector<vector<int>> specialGrid(int n) {
        N = pow(2,n);
        ans.resize(N,vector<int>(N,-1));
        int value = N * N - 1; 
        solve(0,0,value,N);
        return ans;
        
        
    }
};