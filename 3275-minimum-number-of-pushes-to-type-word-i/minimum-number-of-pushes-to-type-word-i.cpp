class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n <= 8){
            return n;
        }

        int n1 = n / 8;
        int n2 = n % 8;

        int ans = 0;
        int multiplier = 1;
        for(int i = 0; i < n1; i++){
            ans += (8 * multiplier);
            multiplier++;
        }


        ans += n2 * multiplier;


        return ans;
        
        
       

        
        
    }
};