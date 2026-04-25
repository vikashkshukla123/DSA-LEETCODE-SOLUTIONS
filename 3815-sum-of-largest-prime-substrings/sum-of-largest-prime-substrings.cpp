class Solution {
public:
bool isPrime(string &s){
    int n = s.length();
    long long val = stoll(s);
    if(val <= 1) return false;
    for(long long i = 2; i * i <= val; i++){
        if(val % i == 0) return false;
    }
    return true;
}
    long long sumOfLargestPrimes(string s) {
        vector<long long>ans;
        unordered_set<long long>st;
        int n = s.length();
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                string str = s.substr(i,j-i+1);
                str.erase(0, str.find_first_not_of('0'));

      
                if (str.empty()) str = "0";

                if(isPrime(str)){
                    if(st.find(stoll(str)) != st.end()) continue;
                    st.insert(stoll(str));
                    ans.push_back(stoll(str));
                    


                }
            }
        }
        sort(ans.rbegin(),ans.rend());
        int ele = ans.size();
        long long sum = 0;
        if(ele <= 3){
            for(int i = 0; i<ele; i++){
                sum += ans[i];
            }
        }else{
            for(int i = 0; i < 3; i++){
                sum += ans[i];
            }
        }

        return sum;
        
    }
};