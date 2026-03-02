class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int ans = 0;
        int win = 0;
        int maxi = -1e9;
        int maxi_idx = -1;
        for(int i = 0; i<n; i++){
            if(maxi < skills[i]){
                maxi = skills[i];
                maxi_idx = i;
            }
        }

        if(k >= n){
            return maxi_idx;
        }
        for(int i = 1; i<n; i++){
            if(skills[i] < skills[ans]){
                win++;
            }else{
                ans = i;
                win = 1;
                
            }

            if(win == k){
                break;
            }
        }
        return ans;
    }
};