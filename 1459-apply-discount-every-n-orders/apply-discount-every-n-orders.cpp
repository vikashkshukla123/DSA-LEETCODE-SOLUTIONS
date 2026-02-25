class Cashier {
    int cnt = 0;
    unordered_map<int,int>mp;
    int peoplecnt;
    int discountkitna;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        peoplecnt = n;
        discountkitna = discount;
        int m = products.size();
        for(int i = 0; i<m; i++){
            mp[products[i]] = prices[i];
        }

        
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        int m = product.size();
        double bill = 0.0;
        for(int i = 0; i<m; i++){
                double product_id = product[i];
                double priceofProduct = mp[product_id];

                double amount_per_product = amount[i] * priceofProduct;
                bill += amount_per_product;
            }

        double money_pay = 0.0;
        if(cnt % peoplecnt == 0){
            money_pay = bill * ((100.0 - discountkitna)/100.0);
            
        }else{
            money_pay = bill;

        }
        return money_pay;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */