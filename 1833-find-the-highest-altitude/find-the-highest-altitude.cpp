class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int>reverse(n+1,0);
        reverse[0] = 0;
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            reverse[i+1] = gain[i] + reverse[i];
            ans = max(ans,reverse[i+1]);
        }

        if(ans < 0){
            return 0;
        }

        return ans;
        
    }
};