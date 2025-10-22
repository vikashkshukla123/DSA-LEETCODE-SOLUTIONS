class Solution {
public:
    string intToRoman(int num) {
        vector<string>v1 = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int>v2 = {1000,900,500,400,100,90,50,40,10,9, 5,4,1};
        string res = "";

       while(num != 0){
        for(int i = 0; i<v1.size(); i++){
            if(num >= v2[i]){
                res += v1[i];
                num = num - v2[i];
                break;
                
            }
        }
       }
       return res;
        
    }
};