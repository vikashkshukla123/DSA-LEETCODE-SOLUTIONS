class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        int area = 0;
        int diagonal = 0;
        for(int i = 0; i<m; i++){
            int l = dimensions[i][0];
            int b = dimensions[i][1];

            int currArea = l*b;
            int currDiagonal = l*l + b*b;

            if(currDiagonal > diagonal){
                area = currArea;
                diagonal = currDiagonal;
            }else if(currDiagonal == diagonal){
                area = max(area, currArea);
            }

        }
        return area;
        
    }
};