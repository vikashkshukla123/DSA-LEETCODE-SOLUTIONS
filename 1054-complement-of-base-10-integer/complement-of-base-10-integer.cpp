class Solution {
public:
    int bitwiseComplement(int n) {
        string s = bitset<32>(n).to_string();

        size_t pos = s.find('1');
        if (pos != string::npos)
           s = s.substr(pos);
        else
            s = "0";

        int m = s.length();
        for(int i = 0; i<m; i++){
            if(s[i] == '1'){
                s[i] = '0';
            }else{
                s[i] = '1';
            }
        }


        int ans = stoi(s,0,2);


        return ans;


        
    }
};