class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        unordered_set<int>st;
        for(int i = 0; i<n; i++){
            if(st.size() == 0  || st.find(bulbs[i]) == st.end()){
                st.insert(bulbs[i]);
            }else if(st.find(bulbs[i]) != st.end()){
                st.erase(bulbs[i]);
            }
        }


        vector<int>ans;
        for(auto it = st.begin(); it != st.end(); it++){
            ans.push_back(*it);
        }

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};