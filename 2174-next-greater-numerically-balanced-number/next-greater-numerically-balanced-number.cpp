class Solution {
public:
bool check(int num){
    string s = to_string(num);
    vector<int>count(10,0);
    for(char c : s){
        count[c -'0']++;
        if(c == '0'){
            return false;
        }
    }
    for(int i = 1; i<=9; i++){
        if(count[i] > 0 && count[i] != i){
            return false;
        }
    }
    return true;
}
    int nextBeautifulNumber(int n) {
        const int maxValue = 1224444;
        for(int i = n+1; i <= maxValue; i++){
            if(check(i)){
                return i;
            }
        }
        return -1;
        
    }
};