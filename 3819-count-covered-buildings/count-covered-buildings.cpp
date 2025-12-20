class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>>yToMinMaxX;
        unordered_map<int,pair<int,int>>xToMinMaxY;


        for(auto&building : buildings){
            int x = building[0];
            int y = building[1];

            if(!yToMinMaxX.count(y)){
                yToMinMaxX[y] = {INT_MAX, INT_MIN};
            }

            if(!xToMinMaxY.count(x)){
                xToMinMaxY[x] = {INT_MAX,INT_MIN};
            }

            yToMinMaxX[y].first = min(yToMinMaxX[y].first,x);
            yToMinMaxX[y].second = max(yToMinMaxX[y].second,x);



            xToMinMaxY[x].first = min(xToMinMaxY[x].first, y);
            xToMinMaxY[x].second = max(xToMinMaxY[x].second,y);


            
        }


        int ans = 0;
        for(auto &building : buildings){
            int x = building[0];
            int y = building[1];


            if(yToMinMaxX.find(y) != yToMinMaxX.end() && xToMinMaxY.find(x) != xToMinMaxY.end()){
                int x1 = yToMinMaxX[y].first;
                int x2 = yToMinMaxX[y].second;




                int y1 = xToMinMaxY[x].first;
                int y2 = xToMinMaxY[x].second;

                if((x > x1 && x < x2) && (y > y1 && y < y2)){
                    ans++;
                }
            }

        }
        return ans;
    }
};