class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int ans = -1;
        int min_capacity = 1e9;
        for(int i = 0; i<n; i++){
            if(capacity[i] >= itemSize){
                if(capacity[i] < min_capacity){
                    min_capacity = capacity[i];
                    ans = i;
                }
            }
        }
        return ans;
        
    }
};