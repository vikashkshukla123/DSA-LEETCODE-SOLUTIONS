class Solution {
public:
    string mergeCharacters(string s, int k) {
        while(true) {
            bool merged = false;

            for(int i = 0; i < s.length(); i++) {
                for(int j = i + 1; j < s.length() && j - i <= k; j++) {
                    if(s[i] == s[j]) {
                        s.erase(j, 1);
                        merged = true;
                        break;   // stop after ONE merge
                    }
                }
                if(merged) break;   // restart from beginning
            }

            if(!merged) break;   // no more merges possible
        }

        return s;
    }
};