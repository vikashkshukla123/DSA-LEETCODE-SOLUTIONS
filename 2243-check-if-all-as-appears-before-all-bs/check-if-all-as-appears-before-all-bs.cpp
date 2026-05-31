class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        if(n == 1) return true;
        int lastPositionofA = -1;
        int firstPositionofB = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == 'a'){
                lastPositionofA = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == 'b'){
                firstPositionofB = i;
                break;
            }
        }
        if(firstPositionofB == -1) return true;
        return (lastPositionofA < firstPositionofB);
    }
};