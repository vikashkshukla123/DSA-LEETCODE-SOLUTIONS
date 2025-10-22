class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows <= 1){
            return s;
        }
        vector<string>v(numRows);
        int index = 0;
        int i = 0;
        while(i < n){

            for(int index = 0; index < numRows && i  < n; index++){
                v[index].push_back(s[i]);
                i++;

            }

            
            for(int index = numRows - 2; index > 0 && i < n; index--){
                v[index].push_back(s[i]);
                i++;
            }
        }

        string res = "";
        for(int i = 0; i<v.size(); i++){
            res += v[i];
        }
        return res;
        
    }
};