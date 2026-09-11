class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>st;
        int n = digits.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(digits[i] == 0) continue;
                    if(i != j && j != k && k != i){
                    string s = to_string(digits[i]);
                    s += to_string(digits[j]);
                    s += to_string(digits[k]);

                    int num = stoi(s);
                    if(st.find(num) != st.end()){
                        continue;
                    }
                    if(num % 2 == 0){
                        st.insert(num);
                        ans++;
                    }
                    

                    }
                }
            }
        }
      return ans;  
    }
};