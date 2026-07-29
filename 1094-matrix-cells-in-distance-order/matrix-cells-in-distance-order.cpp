class Solution {
public:
typedef pair<int,vector<int>>p;
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int dist = abs(row - rCenter) + abs(col - cCenter);
                pq.push({dist,{row,col}});
            }
        }

        vector<vector<int>>result;
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                vector<int>ans;
                auto it = pq.top();
                pq.pop();

                vector<int>vec = it.second;

                ans.push_back(vec[0]);
                ans.push_back(vec[1]);

                result.push_back(ans);

            }
        }

        return result;
    }
};