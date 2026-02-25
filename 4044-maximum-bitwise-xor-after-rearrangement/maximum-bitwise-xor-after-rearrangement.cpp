class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(int i = 0; i<n; i++){
            mp[t[i]]++;

        }

        string t_new = "";
        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                if(mp.find('1') != mp.end()){
                    t_new += '1';
                    mp['1']--;
                    if(mp['1'] == 0){
                        mp.erase('1');
                    }
                }else{
                    t_new += '0';
                    mp['0']--;
                    if(mp['0'] == 0){
                        mp.erase('0');
                    }

                }
            }else{
                if(mp.find('0') != mp.end()){
                    t_new += '0';
                    mp['0']--;
                    if(mp['0'] == 0){
                        mp.erase('0');
                    }
                }else{
                    t_new += '1';
                    mp['1']--;
                    if(mp['1'] == 0){
                        mp.erase('1');
                    }
                }
            }
        }

      


        string XOR = "";
        for(int i = 0; i<n; i++){
            int val1 = s[i] - '0';
            int val2 = t_new[i] - '0';


            int val3 = val1 ^ val2;
            XOR += to_string(val3);

        }

        return XOR;

    }
};