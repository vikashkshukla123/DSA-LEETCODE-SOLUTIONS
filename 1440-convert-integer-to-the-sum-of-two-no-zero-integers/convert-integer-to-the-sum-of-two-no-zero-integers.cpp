class Solution {
public:
bool zeroCheck(int a){
    while(a > 0){
        int b = a % 10;
        if(b == 0) return true;
        a = a / 10;

    }
    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i = 1; i<=n; i++){
            int a = i;
            int b = n-i;
            if(zeroCheck(a) == true || zeroCheck(b) == true){
                continue;
            }
            ans.push_back(a);
            ans.push_back(b);
            break;
        }

return ans;
           
        
    }
};