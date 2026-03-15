class Fancy {
    vector<long long>sequence;
    long long add = 0;
    long long mul = 1;
    
public:
long long mod = 1e9 + 7;
// binary exponentiation for fermat's little therem --> power(mul,m-2);
long long power(long long a, long long b){
    if(b == 0){
        return 1;
    }

    long long half = power(a,b/2);
    long long result = (half * half) % mod;
    if(b % 2 == 1){
        result = (result * a) % mod;
    }
    return result;
}
    Fancy() {
        
    }
    
    void append(int val) {
        long long to_append = ((val - add) % mod + mod) * power(mul,mod-2)%mod;
        sequence.push_back(to_append);
        return;
        
    }
    
    void addAll(int inc) {
        add = (add + inc)  %  mod;
        return;
        
    }
    
    void multAll(int m) {
        add  = (add * m) % mod;
        mul = (mul * m) % mod;
        return;
        
    }
    
    int getIndex(int idx) {
        if(idx >= sequence.size()){
            return -1;
        }

        long long val = sequence[idx];

        int to_return = (val * mul + add) % mod;
        return to_return;
        
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */