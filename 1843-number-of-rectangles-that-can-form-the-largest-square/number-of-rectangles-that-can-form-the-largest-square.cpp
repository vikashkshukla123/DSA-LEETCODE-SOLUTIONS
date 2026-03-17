class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<int>mini(n,0);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            mini[i] = min(rectangles[i][0],rectangles[i][1]);
            maxi = max(maxi,mini[i]);
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(mini[i] == maxi){
                cnt++;
            }
        }

return cnt;
    }
};