class Solution {
public:
int N;
vector<int>parent;
vector<int>rank;

int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    int parent_a = find(a);
    int parent_b = find(b);

    if(parent_a == parent_b){
        return;
    }

    if(rank[parent_a] < rank[parent_b]){
        parent[parent_a] = parent_b;
    }else if(rank[parent_b] < rank[parent_a]){
        parent[parent_b] = parent_a;
    }else{
        parent[parent_b] = parent_a;
        rank[parent_a]++;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        N = n;
        if(connections.size() < N-1){
            return -1;
        }
        parent.resize(N);
        rank.resize(N,0);
        for(int i = 0; i < N; i++){
            parent[i] = i;
        }
        for(int i = 0; i < connections.size(); i++){
            Union(connections[i][0],connections[i][1]);
        }

        int components = 0;
        for(int i = 0; i < N; i++){
           int a = find(i);
           if(a == i){
            components++;
           }
            
        }
return (components - 1);

    }
};