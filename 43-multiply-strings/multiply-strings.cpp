class Solution {
public:

string to_add(string &previous, string &s){
    int i = previous.length() - 1;
    int j = s.length() - 1;
    int carry = 0;

    string we_got = "";

    while(i >= 0 || j >= 0 || carry){

        int val1 = 0, val2 = 0;

        if(i >= 0) val1 = previous[i--] - '0';
        if(j >= 0) val2 = s[j--] - '0';

        int sum = val1 + val2 + carry;

        we_got += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(we_got.begin(), we_got.end());
    return we_got;
}


string multiply(string num1, string num2) {

    int n = num1.length();
    int m = num2.length();

    string previous = "";
    string ans = "";

    for(int i = m - 1; i >= 0; i--){

        string s = "";
        int carry = 0;

        for(int j = n - 1; j >= 0; j--){

            int val1 = num2[i] - '0';
            int val2 = num1[j] - '0';

            int val3 = val1 * val2 + carry;

            int val4 = val3 % 10;
            carry = val3 / 10;

            s += (val4 + '0');
        }

        if(carry){
            s += (carry + '0');
        }

        reverse(s.begin(), s.end());

        if(i == m - 1){
            previous = s;
            continue;
        }

        s += string(m - 1 - i, '0');

        ans = to_add(previous, s);
        previous = ans;
    }
    if(previous[0] == '0'){
        return "0";
    }
    return previous;
}
};