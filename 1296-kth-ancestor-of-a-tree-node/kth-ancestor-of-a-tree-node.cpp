class TreeAncestor {
public:
int cols;
int N;
vector<vector<int>>ancestors;
    TreeAncestor(int n, vector<int>& parent) {
        N = n;
        cols = log2(n) + 1;
        ancestors.resize(N,vector<int>(cols,-1));
        int idx = 0;
        for(int i = 0; i < n; i++){
            ancestors[i][0] = parent[i];
        }

        for(int j = 1; j < cols; j++){
            for(int node = 0; node < n; node++){
                if(ancestors[node][j-1] != -1){
                   ancestors[node][j] =  ancestors[ancestors[node][j-1]][j-1];
                }

            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        int ans = 0;
        int Node = node;

        for(int j = 0; j < cols; j++){
            if(k & (1 << j)){
                Node = ancestors[Node][j];

                if(Node == -1){
                    return -1;
                }

            }
        }


    return Node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */