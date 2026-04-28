class StockPrice {
public:
unordered_map<int,int>mp;
multiset<int>st;
int current_time_stamp = -1;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()){
            st.erase(st.find(mp[timestamp]));
            st.insert(price);
            current_time_stamp = max(current_time_stamp,timestamp);
            mp[timestamp] = price;
        }else{
            st.insert(price);
            current_time_stamp = max(current_time_stamp,timestamp);
            mp[timestamp] = price;
        }
        
    }
    
    int current() {
        return mp[current_time_stamp];
        
    }
    
    int maximum() {
      return *st.rbegin();
        
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */