class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int,int>mp;
        while(n != 0){
            int a = n % 10;
            mp[a]++;
            n = n/10;
        }
        int min_freq = 1e9;
        int min_ele = 1e9;
        for(auto it = mp.begin(); it != mp.end(); it++){
            min_freq = min(min_freq, it->second);

        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second == min_freq){
                min_ele = min(min_ele, it->first);
            }
        }
        return min_ele;
        
    }
};