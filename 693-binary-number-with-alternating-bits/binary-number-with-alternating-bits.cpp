class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = bitset<32>(n).to_string();

            size_t pos = s.find('1');
             if (pos != string::npos)
                 s = s.substr(pos);
             else
               s = "0";


        

       int m = s.length();
       for(int i = 0; i<m-1; i++){
        if(s[i] == s[i+1]){
            return false;
        }
       }
return true;

    }
};