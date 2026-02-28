class Solution {
public:
    string interpret(string command) {
        int n = command.length();
        string ans = "";
        int i = 0;
        while(i < n){
            if(command[i] == 'G'){
                ans += 'G';
                i++;
            }else if(i+1 < n && command[i] == '(' && command[i+1] == ')'){
                ans += 'o';
                i = i + 2;

            }else if(i+3< n && command[i] == '(' && command[i+1] == 'a'){
                ans += "al";
                i = i + 4;
            }
        }
        return ans;
    }
};