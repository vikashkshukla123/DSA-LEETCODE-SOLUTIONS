class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string res;
        res += s[0];
        int freq = 1;
        for(int i = 1; i<n; i++){
            if(s[i] == res.back()){
                res += s[i];
                freq++;
                if(freq > 2){
                    res.pop_back();
                    freq--;
                }
            }else{
                res += s[i];
                freq = 1;
            }

        }
        return res;
        
    }
};