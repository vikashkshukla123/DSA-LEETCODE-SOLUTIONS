class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ans = -1e9;
        sort(lights.begin(),lights.end());
        int n = arrivalTime.size();
        for(int i = 0; i < n; i++){
            int r = arrivalTime[i] % period;

            if(r < lights[lights.size() - 1]){
                continue;
            }else{
                ans = max(ans, period - r);
            }
        }
        return ans == -1e9 ? 0 : ans;
    }
};