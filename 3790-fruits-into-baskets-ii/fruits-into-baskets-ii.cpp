class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int>placed;
        unordered_set<int>st;
        int ans = 0;
        for(int i = 0; i<n; i++){
            bool placed = false;
            for(int j = 0; j<n; j++){
                if(baskets[j] >= fruits[i] &&  st.find(j) == st.end()){
                    placed = true;
                    
                    st.insert(j);
                    break;

                     
                }
            }
            int a = st.size();
            ans = n - a;


        }
        
        return ans;
    }
};