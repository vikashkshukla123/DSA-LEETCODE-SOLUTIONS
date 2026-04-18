#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string base16(long long num, string &digits){
        if(num == 0) return "0";

        string result = "";
        while(num > 0){
            int rem = num % 16;
            result += digits[rem];
            num /= 16;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string base36(long long num, string &digits){
        if(num == 0) return "0";

        string result = "";
        while(num > 0){
            int rem = num % 36;
            result += digits[rem];
            num /= 36;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    string concatHex36(int n) {

        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        long long square = 1LL * n * n;
        long long cube   = 1LL * n * n * n;

        string to_base16 = base16(square, digits);
        string to_base36 = base36(cube, digits);

        return to_base16 + to_base36;
    }
};