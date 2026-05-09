class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int n = points.size();
        if(n == 1 && points[0] != target){
            return -1;
        }
        set<vector<int>>st;
        for(vector<int>&point : points){
            if(point == target){
                return 0;
            }
        }

        for(vector<int>point : points){
            st.insert(point);
        }
        int k = 1;
        while(k != 100){
            vector<vector<int>>newPoints(st.begin(),st.end());
            bool added = false;
            for(int i = 0; i < newPoints.size() - 1; i++){
                for(int j = i + 1; j < newPoints.size(); j++){
                    vector<int>res;
                    int x1 = newPoints[i][0];
                    int y1 = newPoints[i][1];
                    int z1 = newPoints[i][2];

                    int x2 = newPoints[j][0];
                    int y2 = newPoints[j][1];
                    int z2 = newPoints[j][2];

                    res.push_back(floor((x1 + x2) / 2));
                    res.push_back(floor((y1 + y2) / 2));
                    res.push_back(floor((z1 + z2) / 2));

                    if(res == target){
                        return k;
                    }

                    if(st.find(res) == st.end()){
                        st.insert(res);
                        added = true;
                    }
                }
            }
            if(!added) return -1;
            k++;


        }
        return -1;
    }
};