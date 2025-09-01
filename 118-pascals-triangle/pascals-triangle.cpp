class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows == 1){
            vector<int>a;
            a.push_back(1);
            ans.push_back(a);
            return ans;
        }
        vector<int>prev;
        vector<int>a;
        a.push_back(1);
        ans.push_back(a);
        for(int i = 2; i <= numRows; i++){
            vector<int>curr;
            curr.push_back(1);
            int n = prev.size();
            while(n > 0){
                for(int i = 0; i<n-1; i++){
                    curr.push_back(prev[i] + prev[i+1]);
                }
                break;
            }
            curr.push_back(1);
            ans.push_back(curr);

            prev = curr;
                
        }
        return ans;
        
    }
};