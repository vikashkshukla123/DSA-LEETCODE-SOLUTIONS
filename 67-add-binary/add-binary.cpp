class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();

        int i = n-1;
        int j = m-1;
        int carry = 0;

        string res = "";

        while(i >= 0 || j >= 0 || carry > 0){
            int sum = carry;

            if(i >= 0) sum += a[i] - '0';
            if(j >= 0) sum += b[j] - '0';

            if(sum == 2){
                res += "0";
                carry = 1;
            }
            else if(sum == 3){
                res += "1";
                carry = 1; 
            }else if(sum == 0){
                res += "0";
                carry = 0;
            }
            else if(sum == 1){
                res += "1";
                carry = 0;
            }
i--;
j--;



        }





        reverse(res.begin(),res.end());


        return res;
    }
};