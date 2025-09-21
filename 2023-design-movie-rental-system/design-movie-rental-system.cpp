class MovieRentingSystem {
    set<vector<int>>rented;
    unordered_map<int,set<vector<int>>>unrented;
    std::unordered_map<int, std::unordered_map<int, int>> prices;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto i : entries){
            int shop = i[0];
            int movie = i[1];
            int price = i[2];

            unrented[movie].insert({price,shop});
            prices[movie][shop] = price;
        }
        
    }
    
    vector<int> search(int movie) {
        if(unrented.find(movie) == unrented.end()){
            return {};
        }
        vector<int>ans;
        for(auto i : unrented[movie]){
            int shop = i[1];
            ans.push_back(shop);
            if(ans.size() == 5){
                break;
            }

        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = prices[movie][shop];
        rented.insert({price,shop,movie});
        unrented[movie].erase(unrented[movie].find({price,shop}));
        
    }
    
    void drop(int shop, int movie) {
        int price = prices[movie][shop];
        unrented[movie].insert({price,shop});
        rented.erase({price,shop,movie});
        
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;

        for(auto it : rented){
            int shop = it[1];
            int movie = it[2];
            ans.push_back({shop,movie});


            if(ans.size() == 5){
                break;
            }
        }
return ans;
        
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */