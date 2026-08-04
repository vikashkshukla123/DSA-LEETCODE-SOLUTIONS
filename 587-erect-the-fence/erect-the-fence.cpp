class Solution {
public:
int getSlopeValue(const pair<int,int>&p1,const pair<int,int>&p2,const pair<int,int>&p3){
    int x1 = p1.first;
    int y1 = p1.second;

    int x2 = p2.first;
    int y2 = p2.second;

    int x3 = p3.first;
    int y3 = p3.second;

    return ((y2-y1)*(x3-x2) - (x2-x1)*(y3-y2));
}
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n <= 2) return trees;
        sort(trees.begin(),trees.end());
        deque<pair<int,int>>lower;
        deque<pair<int,int>>upper;

        for(int i = 0; i < n; i++){
            int l = lower.size();
            int u = upper.size();

            while(l >= 2 && getSlopeValue(lower[l-1],lower[l-2],{trees[i][0],trees[i][1]}) > 0){
                l--;
                lower.pop_back();
            }
            

            while(u >= 2 && getSlopeValue(upper[u-1],upper[u-2],{trees[i][0],trees[i][1]}) < 0){
                u--;
                upper.pop_back();
            }

            upper.push_back({trees[i][0],trees[i][1]});
            lower.push_back({trees[i][0],trees[i][1]});
            
        }

        set<pair<int,int>>points;
        for(auto &point : upper){
            points.insert(point);
        }

        for(auto &point : lower){
            points.insert(point);
        }


        vector<vector<int>>ans;
        for(auto &point : points){
            ans.push_back({point.first,point.second});
        }


return ans;



        
    }
};