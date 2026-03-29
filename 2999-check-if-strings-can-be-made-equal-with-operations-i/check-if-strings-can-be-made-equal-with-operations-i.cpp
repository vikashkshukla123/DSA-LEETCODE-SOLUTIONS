class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.length();
        for(int i = 0; i<=n-2; i++){
            int j = i + 2;

            if(s1[i] == s2[j] && s1[j] == s2[i]){
                swap(s1[i], s1[j]);
            }
        }

        return (s1 == s2);


        
    }
};