class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int>height2;
        for(int i = 0; i<n; i++){
            height2.push_back(heights[i]);
        }
        sort(height2.begin(),height2.end());
        int i = 0;
        int j = 0;
        int ans = 0;

        while(i < n && j < n){
            if(heights[i] == height2[j]){
                i++;
                j++;
                continue;
            }
            else{
                ans++;
                i++;
                j++;
            }
            
        }
        return ans;

    }
};