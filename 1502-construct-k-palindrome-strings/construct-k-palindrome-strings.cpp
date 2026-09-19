class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k > n) return false;
        unordered_map<char,int>mp;
        int cntOdd = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second % 2 == 1){
                cntOdd++;
            }
        }

        if(cntOdd > k){
            return false;
        }

        return true;
    }
};