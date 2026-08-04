class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0; i <= n; i++){
            int cnt = 0;
            for(int bit = 0; bit < 19; bit++){
                if(((1 << bit) & i) != 0){
                    cnt++;
                } 
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};