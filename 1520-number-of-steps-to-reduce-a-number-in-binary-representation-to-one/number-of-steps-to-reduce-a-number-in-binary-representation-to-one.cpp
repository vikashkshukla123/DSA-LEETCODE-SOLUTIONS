class Solution {
public:
string addone(string &s){
    char carry = '0';
    string ans = "";
    int n = s.length();
    int i = n-1;
    while(i >= 0){
        if(i == n-1){
            if(s[i] == '1' && carry == '0'){
                ans += '0';
                carry = '1';
            }else if(s[i] == '0' && carry == '0'){
                ans += '1';
                carry = '0';
            }else if(s[i] == '1' && carry == '1'){
                ans += '1';
                carry = '1';
            }

        }else{
            if(s[i] == '1' && carry == '0'){
                ans += '1';
                carry = '0';
            }else if(s[i] == '1' && carry == '1'){
                ans += '0';
                carry = '1';
            }else if(s[i] == '0' && carry == '1'){
                ans += '1';
                carry = '0';
            }else if(s[i] == '0' && carry == '0'){
                ans += '0';
                carry = '0';
            }

        }
        i--;
    }

    if(carry == '1'){
        ans += '1';
    }


        

    reverse(ans.begin(),ans.end());

    return ans;

}
    int numSteps(string s) {
        int cnt = 0;
        
        while(true){
            int n = s.length();
            if(n == 1 && s[0] == '1'){
                return 0;
            }
            if(s[n-1] == '1'){
                string temp = addone(s);

                s = temp;

                // case of odd;
            }else{
                string temp = s.substr(0,n-1);

                s = temp;
                // case of even
            }
            cnt++;

            if(s.length() == 1  && s[0] == '1'){
                break;
            }



        }
        return cnt;
    }
};