class Solution {
public:
bool isMirror(int num, unordered_map<int,int>&mirror){
    int original = num;
    int numStart = 0;
    bool changed = false;
    while(num != 0){
        int val = num %  10;
        if(mirror.find(val) != mirror.end()){

            if(val != mirror[val]){
                changed = true;
            }
        }else{
            return false;
        }
        numStart = numStart * 10 + mirror[val];
        num = num / 10;
    }
    return changed;
    
}
    int rotatedDigits(int n) {
        unordered_map<int,int>mirror;
        mirror[0] = 0;
        mirror[1] = 1;
        mirror[8] = 8;
        mirror[2] = 5;
        mirror[5] = 2;
        mirror[6] = 9;
        mirror[9] = 6;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(isMirror(i,mirror)){
                ans++;
            }
        }
        return ans;
    }
};