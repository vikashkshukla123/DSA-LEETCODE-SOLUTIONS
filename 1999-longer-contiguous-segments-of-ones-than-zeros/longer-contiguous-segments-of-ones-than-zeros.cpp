class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.length();
        int longestOnes = 0;
        int longestZero = 0;
        int currentOnes = 0;
        int currentZeros = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                currentOnes = 0;
                currentZeros++;
                longestZero = max(longestZero,currentZeros);
            }else{
                currentZeros = 0;
                currentOnes++;
                longestOnes = max(longestOnes, currentOnes);
            }
        }

        return (longestOnes > longestZero);

        
    }
};