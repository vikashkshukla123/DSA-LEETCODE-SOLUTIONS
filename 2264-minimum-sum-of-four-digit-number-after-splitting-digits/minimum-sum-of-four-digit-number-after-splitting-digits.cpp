class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
    

        string s1 = "";
        s1 += s[0];
        s1 += s[2];

        string s2 = "";
        s2 += s[1];
        s2 += s[3];

        int val1 = stoi(s1);
        int val2 = stoi(s2);


        return (val1 + val2);
        
        
    }
};