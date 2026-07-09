class DSU{
    public :
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) return;


        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y]  = parent_x;
        }else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }


};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = nums.size();
        vector<bool>ans;
        DSU dsu;

        dsu.parent.resize(n);
        dsu.rank.resize(n,0);

        for(int i = 0; i < n; i++){
            dsu.parent[i] = i;
        }


          for(int node = 1; node < n; node++){
            if(nums[node] - nums[node-1] <= maxDiff){
                dsu.Union(node, node-1);
            }
        }

    
        

        for(int i = 0; i < queries.size(); i++){
            int node1 = queries[i][0];
            int node2 = queries[i][1];

            int parent1 = dsu.find(node1);
            int parent2 = dsu.find(node2);

            if(parent1 == parent2){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        



       

return ans;
        
    }
};