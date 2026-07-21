class Solution {
public:
    string intToRoman(int num) {
        vector<string>ones = {",", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string>tens = {",","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX","XC"};
        vector<string>hundreds = {",", "C", "CC", "CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string>thousands = {",","M","MM","MMM"};

        string ans  =  (thousands[num/1000] + hundreds[(num % 1000) / 100] + tens[(num % 100)/10] + ones[(num % 10)]);


       string result = "";
       for(int i = 0; i < ans.length(); i++){
        if(ans[i] == ','){
            continue;
        }
        result += ans[i];
       }

       return result;
    }
};