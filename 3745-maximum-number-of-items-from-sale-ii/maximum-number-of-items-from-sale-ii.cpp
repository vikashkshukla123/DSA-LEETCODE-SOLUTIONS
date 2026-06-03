class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheapPrice = 1e9;
        int maxFactor = -1e9;
        unordered_set<int>st;

        for(int i = 0; i < n; i++){
            int price = items[i][1];
            int factor = items[i][0];
            st.insert(factor);

            cheapPrice = min(cheapPrice, price);
            maxFactor = max(maxFactor, factor);
        }


        vector<int>seiveFactors(maxFactor+1,0);

        for(int i = 0; i < n; i++){
            seiveFactors[items[i][0]] += 1;
        }
        for(int i = 1; i <= maxFactor; i++){
            if(seiveFactors[i] == 0)continue;
            for(int j = i * 2; j <= maxFactor; j += i){
                seiveFactors[i] += seiveFactors[j];
            }
        }

        for(int i = 1; i <= maxFactor; i++){
            if(seiveFactors[i] > 0){
                seiveFactors[i] = seiveFactors[i] - 1;
            }
        }

        vector<pair<int,int>>vec;
        for(int i = 0; i < n; i++){
            int factor = items[i][0];
            int price = items[i][1];

            if((price <= 2 * cheapPrice) && (seiveFactors[factor] > 0)){
                vec.push_back({price, seiveFactors[factor]});
            }
        }

        sort(vec.begin(),vec.end());
        int copies = 0;
        for(int i = 0; i < vec.size(); i++){
            int min_copy = min(vec[i].second, budget / vec[i].first); 
            budget = budget - (min_copy * vec[i].first);
            copies += min_copy + min_copy;

        }
        if(budget >= cheapPrice){
            copies += (budget / cheapPrice);
        }


return copies;
    }
};