class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            string op = operations[i];
            if(op == "--X" || op == "X--"){
                ans -= 1;
            }if(op == "X++" || op == "++X"){
                ans += 1;
            }
        }
        return ans;
    }
};