class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i = 0; i<n; i++){
            if(i % 2 == 0){
                mp1[s1[i]] += 1;
            }else{
                mp1[s1[i]] -= 1;
            }

        }


        for(int i = 0; i<n; i++){
            if(i % 2 == 0){
                mp2[s2[i]] += 1;
            }else{
                mp2[s2[i]] -= 1;
            }

        }

        for(auto it = mp1.begin(); it != mp1.end(); it++){
          char ch = it->first;
          int f1 = it->second;


          if(mp2.find(ch) == mp2.end()){
            return false;
          }


          if(mp2[ch] != f1){
            return false;
          }
        }


        for(auto it = mp2.begin(); it != mp2.end(); it++){
            char ch = it->first;
          int f1 = it->second;


          if(mp1.find(ch) == mp1.end()){
            return false;
          }


          if(mp1[ch] != f1){
            return false;
          }

        }


        return true;



        
    }
};