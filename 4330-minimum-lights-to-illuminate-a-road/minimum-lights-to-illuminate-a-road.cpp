class Solution {
public:
    int minLights(vector<int>& lights) {
        vector<vector<int>>merged;
        int n = lights.size();
        for(int i = 0; i < n; i++){
            if(lights[i] != 0){
                int left = max(0, i - lights[i]);
                int right = min(n-1, i + lights[i]);
                merged.push_back({left,right});
            }
        }

        if(merged.size() == 0){
            return ceil((double)n/3);
        }

        sort(merged.begin(),merged.end());
        vector<vector<int>>actual;
        for(int i = 0; i < merged.size(); i++){
            if(actual.empty() || actual.back()[1] < merged[i][0]){
                actual.push_back(merged[i]);
            }else{
                actual.back()[1] = max(actual.back()[1], merged[i][1]);
            }
        }
        int ans = 0;

        if(actual[0][0] > 0){
            int gap = actual[0][0] - 0;
            ans += ceil((double)gap/3);
        }

        for(int i = 0; i < actual.size() - 1; i++){
            int gap = actual[i+1][0] - actual[i][1] - 1;
            if(gap > 0){
                ans += ceil((double)gap/3);

            }
        }

        if(actual.back()[1] < n - 1){
            int gap = (n-1)   - actual.back()[1];
            ans += ceil((double)gap/3);
        }


        
return ans;












        



        

        
    }
};