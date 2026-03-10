class Solution {
public:
bool isDigit(char ch){
    if(ch >= '0' && ch <= '9') return true;
    return false;

}
    int myAtoi(string s) {
        int n = s.length();
        int ans = 0;
        int i = 0;
        bool negative = false;
        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }
            if(i < n && (s[i] == '-' || s[i] == '+')){
                if(s[i] == '-'){
                    negative = true;
                    
                }
                i++;
            }
            

            while(i < n && s[i] == '0'){
                i++;
            }




            while(i < n && isDigit(s[i])){
                int digit = s[i] - '0';
                if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)){
                    if(negative){
                        return INT_MIN;

                    }
                    return INT_MAX;
                }
                


                ans = ans * 10 + digit;


            i++;
            }

            if(i >= n ||  !isDigit(s[i])) break;

            













            





        }


        if(negative){
            return -ans;
        };
        return ans;
    }
};