class Solution {
public:
    int getSum(string &str){
        int n = str.length();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += str[i] - '0';
        }
        return sum;
    }
       

    int getLucky(string s, int k) {
        string str = "";
        for(char ch : s){
            str += to_string(ch - 'a' + 1);
        }
        int ans;
    
        for(int i = 0; i<k; i++){
            ans = getSum(str);
            str = to_string(ans);

        }
        return ans;

        
    }
};
