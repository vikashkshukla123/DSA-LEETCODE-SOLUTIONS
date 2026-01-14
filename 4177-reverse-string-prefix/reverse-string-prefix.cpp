class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = k-1;
        while(i <= j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
return s;
        
    }
};