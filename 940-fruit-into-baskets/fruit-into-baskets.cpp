class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_map<int,int>freq;
        while(j < n){
            freq[fruits[j]]++;
            if(freq.size() <= 2){
                ans  = max(ans, j - i + 1);
            }else{
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0) freq.erase(fruits[i]);
                i++;
            }
            j++;

        }
        return ans;
        
    }
};