class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int,int>mp;
        int n = items.size();
        int m = queries.size();
        for(int i = 0; i<n; i++){
            int price = items[i][0];
            int beauty = items[i][1];

            if(mp.find(price) == mp.end()){
                mp[price] = beauty;
            }else{
                int beauty1 = mp[price];
                int newBeauty = beauty;

                mp.erase(price);

                mp[price] = max(beauty1, newBeauty);
            }
        }
        vector<vector<int>>naya;
        for(auto &[price , beauty] : mp){
            vector<int>v;
            v.push_back(price);
            v.push_back(beauty);

            naya.push_back(v);
        }

        sort(naya.begin(),naya.end());
        vector<int>price;
        for(int i = 0; i<naya.size(); i++){
            price.push_back(naya[i][0]);
        }

        vector<int>maxBeauty(naya.size(),0);
        vector<int>ans;
        maxBeauty[0] = naya[0][1];
        for(int i = 1; i<naya.size(); i++){
            maxBeauty[i] = max(maxBeauty[i-1],naya[i][1]);
        }

        for(int i = 0; i<m; i++){
            int idx = upper_bound(price.begin(),price.end(), queries[i]) - price.begin();
            int original_idx = idx - 1;
            if(original_idx >= 0){
                ans.push_back(maxBeauty[original_idx]);
            }else{
                ans.push_back(0);
            }
        }
        

        

     return ans;
        
    }
};