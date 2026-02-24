class Solution {
public:
    int binaryGap(int n) {
        string s = bitset<32>(n).to_string();

        size_t pos = s.find('1');
             if (pos != string::npos)
                 s = s.substr(pos);
             else
               s = "0";

        

        int ans = 0;
        for(int i = 0; i<s.length()-1; i++){
            if(s[i] == '0') continue;
            for(int j = i+1; j <s.length(); j++){
                if(s[j] == '0') continue;
                

                ans = max(ans, j - i);
                break;
            }
        }

        return ans;
    }
};