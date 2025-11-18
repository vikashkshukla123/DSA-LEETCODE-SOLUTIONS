class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while(i < n-1){
            if(bits[i] == 0){
                i = i+1;
            }else{
                if(bits[i] == 1){
                    i = i+2;
                }
            }

        }
        
        if(i >= n) return false;
        return true;
    }
};