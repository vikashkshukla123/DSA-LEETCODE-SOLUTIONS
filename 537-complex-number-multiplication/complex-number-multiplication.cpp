class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();

        int idx1 = num1.find('+');
        int idx2 = num2.find('+');

        string a_ = num1.substr(0,idx1 + 1);
        string c_ = num2.substr(0,idx2 + 1);

        string b_ = num1.substr(idx1 + 1);
        string d_ = num2.substr(idx2 + 1);

        int a = stoi(a_);
        int b = stoi(b_);
        int c = stoi(c_);
        int d = stoi(d_);

        int real = (a*c - b*d);
        int imaginary = (a*d + b*c);

        return (to_string(real) + "+" + to_string(imaginary) + "i");

        
    }
};