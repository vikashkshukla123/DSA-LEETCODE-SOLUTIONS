class Solution {
    vector<vector<int>>ans;
public:
void f(int num1, int n, int k, vector<int>a){
    if(k == 0) {
        ans.push_back(a);
    return;
    }

    for(int i = num1 ; i<=n; i++){
        a.push_back(i);
         f(i + 1, n, k-1, a);

         a.pop_back();
    }

}
    vector<vector<int>> combine(int n, int k) {
        vector<int>a;
        f(1,n,k,a);


        return ans;
        
    }
};