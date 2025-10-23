class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>>ans;
        sort(points.begin(), points.end());
        int prevs = points[0][0];
        int preve = points[0][1];
        int cnt = 1;

        for(int i = 1; i<n; i++){
            int currs = points[i][0];
            int curre = points[i][1];


            if(currs > preve){
                cnt++;
                prevs = currs;
                preve = curre;

            }else{
                prevs = max(prevs, currs);
                preve = min(preve, curre);
            }

        }
        return cnt;
        
    }
};