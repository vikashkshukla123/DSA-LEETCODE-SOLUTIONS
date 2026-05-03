class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if(s == goal) return true;
        string naya = "";
        string original = s;
        while(true){
            string s1 = s.substr(0,1);
            string s2 = s.substr(1);

            naya += s2;
            naya += s1;

            if(naya == goal) return true;
            if(naya == original) break;
            s = naya;
            naya = "";

        }

        return false;
    }
};