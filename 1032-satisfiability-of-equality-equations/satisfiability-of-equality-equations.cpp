
class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);

        if(a_parent == b_parent){
            return;
        }

        if(rank[a_parent] < rank[b_parent]){
            parent[a_parent] = b_parent;
        }else if(rank[b_parent] < rank[a_parent]){
            parent[b_parent] = a_parent;
        }else{
            parent[b_parent] = a_parent;
            rank[a_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        int n = equations.size();
        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(int i = 0 ; i < n; i++){
            int idx1 = equations[i][0] - 'a';
            int idx2 = equations[i][3] - 'a';

            char sign = equations[i][1];
            if(sign == '='){
                Union(idx1,idx2);
            }
        }

        for(int i = 0; i < n; i++){
            int idx1 = equations[i][0] - 'a';
            int idx2 = equations[i][3] - 'a';

            char sign = equations[i][1];
            if(sign == '!'){
                int idx1_parent = find(idx1);
                int idx2_parent = find(idx2);

                if(idx1_parent == idx2_parent){
                    return false;
                }
            }

        }
        return true;
    }
};