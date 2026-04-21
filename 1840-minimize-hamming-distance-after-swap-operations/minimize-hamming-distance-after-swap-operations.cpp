class Solution {
public:
// DSU using path compression and rank comression
vector<int>rank;
vector<int>parent;

// Find with path Compression
int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void Union(int x, int y){
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY){
        return;
    }
    // union by rank
    if(rank[rootX] < rank[rootY]){
        swap(rootX,rootY);
    }
    parent[rootY] = rootX;

    if(parent[rootX] == parent[rootY]){
        rank[rootX]++;
    }
}



    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
        // union of allowed swaps
        for(auto &vec : allowedSwaps){
            Union(vec[0],vec[1]);
        }
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i = 0; i<n; i++){
            int parent = find(i);
            mp[parent][source[i]]++;
        }

        int hammingDistance = 0;
        for(int i = 0; i<n; i++){
            int need = target[i];
            int parent = find(i);

            if(mp[parent][need] > 0){
                mp[parent][need] -= 1;
            }else{
                hammingDistance++;
            }
        }
        return hammingDistance;
        
    }
};